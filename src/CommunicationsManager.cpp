#include "CommunicationManager.h"
#include <istream>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <fmt/format.h>
#include <time.h>
#include <random>
#include "FastDDS.h"
#include "PacketTypes/header.h"

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds;
using namespace eprosima::fastrtps::rtps;
using namespace eprosima::fastrtps::types;
using namespace eprosima::fastrtps;
using namespace eprosima::fastdds::rtps;

CommunicationManager::CommunicationManager(std::string_view hostname, bool isServer)
{
    if(isServer)
        _participant = _createServerParticipant(hostname);
    else
        _participant = _createClientParticipant(hostname);

    _publisher = _participant->create_publisher(PUBLISHER_QOS_DEFAULT);
    _subscriber = _participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
    _readerFree = true;
    _callbackFree = true;
    _writerFree = true;
    _run = true;
    _readerThread = std::thread(&CommunicationManager::_dataRecievedHandler, this);
    _writerThread = std::thread(&CommunicationManager::_writeWorker, this);

}

CommunicationManager::~CommunicationManager()
{
    shutdown();
    _readerThread.join();

    for(const auto [name, topic] : _topics)
        _participant->delete_topic(topic);

    for(const auto i : _writers)
        _publisher->delete_datawriter(i);

    for(const auto i : _readers)
        _subscriber->delete_datareader(i);

    _publisher->delete_contained_entities();
    _participant->delete_publisher(_publisher);

    _subscriber->delete_contained_entities();
    _participant->delete_subscriber(_subscriber);

    if(_participant->delete_contained_entities() != ReturnCode_t::RETCODE_OK)
        return;

    DomainParticipantFactory::get_instance()->delete_participant(_participant);
}

int CommunicationManager::addDataWriter(std::string topicName)
{
    const auto& topic = _topics.at(topicName);
    auto* writer = _publisher->create_datawriter(topic, DATAWRITER_QOS_DEFAULT);
    _writers.push_back(writer);
    return _writers.size() - 1;
}

void CommunicationManager::_writeWorker()
{
    while(_run)
    {
        std::unique_lock lck(_writerMux);
        _writerCV.wait(lck, [this](){ return _writerFree && !_data.empty(); });
        _writerFree = false;

        auto data = _data.front();
        _data.pop();
        auto now = std::chrono::system_clock::now();
        auto nowMS = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto epoch = nowMS.time_since_epoch();

        ((Header*)data.data)->timeSent(std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count());

        _writers[data.writeID]->write(data.data, eprosima::fastrtps::rtps::InstanceHandle_t());
        free(data.data);

        _writerFree = true;
        _writerCV.notify_all();
    }
}

void CommunicationManager::shutdown()
{
    _run = false;
}

void CommunicationManager::_dataRecievedHandler()
{
    using namespace std::chrono_literals;

    SampleInfo info;
    std::byte data[100];
    eprosima::fastrtps::Duration_t timeout (0, 50000000);
    while(_run)
    {
        std::unique_lock readerLock(_readerMux);
        _readerCV.wait(readerLock, [this](){ return _readerFree; });
        _readerFree = false;
        for(int i = 0; i < _readers.size(); i++)
        {
            ConditionSeq conditions;
            if(_waitSets[i]->wait(conditions, timeout) == ReturnCode_t::RETCODE_OK)
            {
                while(_readers[i]->read_next_sample(data, &info) == ReturnCode_t::RETCODE_OK)
                {
                    const std::string& name = _readers[i]->get_topicdescription()->get_name();

                    std::unique_lock callbackLock(_callbackMux);
                    _callbackCV.wait(callbackLock,[this](){ return _callbackFree; });
                    _callbackFree = false;
                    auto& callbacks = _callbacks.at(name);
                    for(auto& c : callbacks)
                        c(data);
                    _callbackFree = true;
                    callbackLock.unlock();
                    _callbackCV.notify_all();
                }
            }
        }
        _readerFree = true;
        readerLock.unlock();
        _readerCV.notify_all();
        // Give time for resources to be added
        std::this_thread::sleep_for(50ms);
    }
}

eprosima::fastdds::dds::DomainParticipant *CommunicationManager::_createServerParticipant(std::string_view hostname)
{
    // Get default participant QoS
    DomainParticipantQos server_qos = PARTICIPANT_QOS_DEFAULT;

    // Set participant as SERVER
    server_qos.wire_protocol().builtin.discovery_config.discoveryProtocol =
            DiscoveryProtocol_t::SERVER;

    // Set SERVER's GUID prefix
    std::istringstream("44.53.00.5f.45.50.52.4f.53.49.4d.41") >> server_qos.wire_protocol().prefix;
    server_qos.wire_protocol().builtin.discovery_config.leaseDuration = c_TimeInfinite;

    // Set SERVER's listening locator for PDP
    IPData data = _parseIP(hostname);
    Locator_t locator;
    locator.kind = LOCATOR_KIND_TCPv4;
    IPLocator::setLogicalPort(locator, data.port);
    IPLocator::setIPv4(locator, data.ip);
    IPLocator::setWan(locator, data.ip);
    server_qos.wire_protocol().builtin.metatrafficUnicastLocatorList.push_back(locator);

    server_qos.transport().use_builtin_transports = false;
    auto tcpTransport = std::make_shared<TCPv4TransportDescriptor>();
    tcpTransport->wait_for_tcp_negotiation = false;
    tcpTransport->sendBufferSize = tcpTransport->max_message_size() * 16;
    tcpTransport->receiveBufferSize = tcpTransport->max_message_size() * 16;
    tcpTransport->add_listener_port(data.port);
    tcpTransport->set_WAN_address(data.ip);
    server_qos.transport().user_transports.push_back(tcpTransport);
    
    return DomainParticipantFactory::get_instance()->create_participant(0, server_qos);
}

eprosima::fastdds::dds::DomainParticipant *CommunicationManager::_createClientParticipant(std::string_view hostname)
{
    // Get default participant QoS
    DomainParticipantQos client_qos = PARTICIPANT_QOS_DEFAULT;

    // Set participant as CLIENT
    client_qos.wire_protocol().builtin.discovery_config.discoveryProtocol =
            DiscoveryProtocol_t::CLIENT;
    client_qos.name("Server");

    client_qos.wire_protocol().builtin.discovery_config.leaseDuration = c_TimeInfinite;
    client_qos.name(fmt::format("Client-{}", time(NULL)));

    // Set SERVER's GUID prefix
    RemoteServerAttributes remote_server_att;
    remote_server_att.ReadguidPrefix("44.53.00.5f.45.50.52.4f.53.49.4d.41");

    // Set SERVER's listening locator for PDP
    IPData data = _parseIP(hostname);
    Locator_t locator;
    locator.kind = LOCATOR_KIND_TCPv4;
    IPLocator::setLogicalPort(locator, data.port);
    srand(time(NULL));
    uint32_t randPort = rand() % 25565;
    IPLocator::setPhysicalPort(locator, randPort);
    IPLocator::setIPv4(locator, data.ip);
    remote_server_att.metatrafficUnicastLocatorList.push_back(locator);

    // Add remote SERVER to CLIENT's list of SERVERs
    client_qos.wire_protocol().builtin.discovery_config.m_DiscoveryServers.push_back(remote_server_att);

    client_qos.transport().use_builtin_transports = false;
    auto tcpTransport = std::make_shared<TCPv4TransportDescriptor>();
    tcpTransport->sendBufferSize = tcpTransport->max_message_size() * 16;
    tcpTransport->receiveBufferSize = tcpTransport->max_message_size() * 16;

    std::default_random_engine gen(time(NULL));
    std::uniform_int_distribution rdn(49152, 65535);
    tcpTransport->add_listener_port(rdn(gen));
    tcpTransport->wait_for_tcp_negotiation = false;

    client_qos.transport().user_transports.push_back(tcpTransport);

    // Create CLIENT
    return DomainParticipantFactory::get_instance()->create_participant(0, client_qos);
}

CommunicationManager::IPData CommunicationManager::_parseIP(std::string_view hostname)
{
    // Lib uses const std::string&. This prevents redundent copies
    size_t portSeperator = hostname.find(":");
    if(portSeperator == std::string_view::npos)
        throw HostnameException("No port given. The port must come at the end of the hostname, seperated by a ':'");
    std::string name(hostname.begin(), hostname.begin() + portSeperator);
    std::string portStr(hostname.begin() + portSeperator + 1, hostname.end());

    bool isURL = !IPLocator::isIPv4(name);
    IPData data;
    if(isURL)
    {
        auto response = IPLocator::resolveNameDNS(name);
        if(response.first.size() > 0)
            data.ip = response.first.begin()->data();
        else
            throw HostnameException("Could not resolve hostname " + name);
    }
    else
        data.ip = name;
    data.port = std::stoi(portStr);

    return data;
}
