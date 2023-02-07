// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file wheelData.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "PacketTypes/wheelData.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

WheelData::WheelData()
{
    // m_head com.eprosima.fastdds.idl.parser.typecode.StructTypeCode@551bdc27

    // m_velocity com.eprosima.idl.parser.typecode.PrimitiveTypeCode@58fdd99
    m_velocity = 0.0;
    // m_distTravelled com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6b1274d2
    m_distTravelled = 0.0;

}

WheelData::~WheelData()
{



}

WheelData::WheelData(
        const WheelData& x)
{
    m_head = x.m_head;
    m_velocity = x.m_velocity;
    m_distTravelled = x.m_distTravelled;
}

WheelData::WheelData(
        WheelData&& x) noexcept 
{
    m_head = std::move(x.m_head);
    m_velocity = x.m_velocity;
    m_distTravelled = x.m_distTravelled;
}

WheelData& WheelData::operator =(
        const WheelData& x)
{

    m_head = x.m_head;
    m_velocity = x.m_velocity;
    m_distTravelled = x.m_distTravelled;

    return *this;
}

WheelData& WheelData::operator =(
        WheelData&& x) noexcept
{

    m_head = std::move(x.m_head);
    m_velocity = x.m_velocity;
    m_distTravelled = x.m_distTravelled;

    return *this;
}

bool WheelData::operator ==(
        const WheelData& x) const
{

    return (m_head == x.m_head && m_velocity == x.m_velocity && m_distTravelled == x.m_distTravelled);
}

bool WheelData::operator !=(
        const WheelData& x) const
{
    return !(*this == x);
}

size_t WheelData::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += Header::getMaxCdrSerializedSize(current_alignment);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t WheelData::getCdrSerializedSize(
        const WheelData& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += Header::getCdrSerializedSize(data.head(), current_alignment);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

void WheelData::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_head;
    scdr << m_velocity;
    scdr << m_distTravelled;

}

void WheelData::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_head;
    dcdr >> m_velocity;
    dcdr >> m_distTravelled;
}

/*!
 * @brief This function copies the value in member head
 * @param _head New value to be copied in member head
 */
void WheelData::head(
        const Header& _head)
{
    m_head = _head;
}

/*!
 * @brief This function moves the value in member head
 * @param _head New value to be moved in member head
 */
void WheelData::head(
        Header&& _head)
{
    m_head = std::move(_head);
}

/*!
 * @brief This function returns a constant reference to member head
 * @return Constant reference to member head
 */
const Header& WheelData::head() const
{
    return m_head;
}

/*!
 * @brief This function returns a reference to member head
 * @return Reference to member head
 */
Header& WheelData::head()
{
    return m_head;
}
/*!
 * @brief This function sets a value in member velocity
 * @param _velocity New value for member velocity
 */
void WheelData::velocity(
        float _velocity)
{
    m_velocity = _velocity;
}

/*!
 * @brief This function returns the value of member velocity
 * @return Value of member velocity
 */
float WheelData::velocity() const
{
    return m_velocity;
}

/*!
 * @brief This function returns a reference to member velocity
 * @return Reference to member velocity
 */
float& WheelData::velocity()
{
    return m_velocity;
}

/*!
 * @brief This function sets a value in member distTravelled
 * @param _distTravelled New value for member distTravelled
 */
void WheelData::distTravelled(
        float _distTravelled)
{
    m_distTravelled = _distTravelled;
}

/*!
 * @brief This function returns the value of member distTravelled
 * @return Value of member distTravelled
 */
float WheelData::distTravelled() const
{
    return m_distTravelled;
}

/*!
 * @brief This function returns a reference to member distTravelled
 * @return Reference to member distTravelled
 */
float& WheelData::distTravelled()
{
    return m_distTravelled;
}


size_t WheelData::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;






    return current_align;
}

bool WheelData::isKeyDefined()
{
    return false;
}

void WheelData::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
       
}
