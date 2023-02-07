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
 * @file header.cpp
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

#include "PacketTypes/header.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

Header::Header()
{
    // m_id com.eprosima.idl.parser.typecode.PrimitiveTypeCode@23a5fd2
    m_id = 0;
    // m_timeRec com.eprosima.idl.parser.typecode.PrimitiveTypeCode@78a2da20
    m_timeRec = 0;
    // m_timeSent com.eprosima.idl.parser.typecode.PrimitiveTypeCode@dd3b207
    m_timeSent = 0;

}

Header::~Header()
{



}

Header::Header(
        const Header& x)
{
    m_id = x.m_id;
    m_timeRec = x.m_timeRec;
    m_timeSent = x.m_timeSent;
}

Header::Header(
        Header&& x) noexcept 
{
    m_id = x.m_id;
    m_timeRec = x.m_timeRec;
    m_timeSent = x.m_timeSent;
}

Header& Header::operator =(
        const Header& x)
{

    m_id = x.m_id;
    m_timeRec = x.m_timeRec;
    m_timeSent = x.m_timeSent;

    return *this;
}

Header& Header::operator =(
        Header&& x) noexcept
{

    m_id = x.m_id;
    m_timeRec = x.m_timeRec;
    m_timeSent = x.m_timeSent;

    return *this;
}

bool Header::operator ==(
        const Header& x) const
{

    return (m_id == x.m_id && m_timeRec == x.m_timeRec && m_timeSent == x.m_timeSent);
}

bool Header::operator !=(
        const Header& x) const
{
    return !(*this == x);
}

size_t Header::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);



    return current_alignment - initial_alignment;
}

size_t Header::getCdrSerializedSize(
        const Header& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);



    return current_alignment - initial_alignment;
}

void Header::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_id;
    scdr << m_timeRec;
    scdr << m_timeSent;

}

void Header::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_id;
    dcdr >> m_timeRec;
    dcdr >> m_timeSent;
}

/*!
 * @brief This function sets a value in member id
 * @param _id New value for member id
 */
void Header::id(
        uint32_t _id)
{
    m_id = _id;
}

/*!
 * @brief This function returns the value of member id
 * @return Value of member id
 */
uint32_t Header::id() const
{
    return m_id;
}

/*!
 * @brief This function returns a reference to member id
 * @return Reference to member id
 */
uint32_t& Header::id()
{
    return m_id;
}

/*!
 * @brief This function sets a value in member timeRec
 * @param _timeRec New value for member timeRec
 */
void Header::timeRec(
        int64_t _timeRec)
{
    m_timeRec = _timeRec;
}

/*!
 * @brief This function returns the value of member timeRec
 * @return Value of member timeRec
 */
int64_t Header::timeRec() const
{
    return m_timeRec;
}

/*!
 * @brief This function returns a reference to member timeRec
 * @return Reference to member timeRec
 */
int64_t& Header::timeRec()
{
    return m_timeRec;
}

/*!
 * @brief This function sets a value in member timeSent
 * @param _timeSent New value for member timeSent
 */
void Header::timeSent(
        int64_t _timeSent)
{
    m_timeSent = _timeSent;
}

/*!
 * @brief This function returns the value of member timeSent
 * @return Value of member timeSent
 */
int64_t Header::timeSent() const
{
    return m_timeSent;
}

/*!
 * @brief This function returns a reference to member timeSent
 * @return Reference to member timeSent
 */
int64_t& Header::timeSent()
{
    return m_timeSent;
}


size_t Header::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;






    return current_align;
}

bool Header::isKeyDefined()
{
    return false;
}

void Header::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
       
}
