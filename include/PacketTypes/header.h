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
 * @file header.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_HEADER_H_
#define _FAST_DDS_GENERATED_HEADER_H_


#include <fastrtps/utils/fixed_size_string.hpp>

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(header_SOURCE)
#define header_DllAPI __declspec( dllexport )
#else
#define header_DllAPI __declspec( dllimport )
#endif // header_SOURCE
#else
#define header_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define header_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure Header defined by the user in the IDL file.
 * @ingroup HEADER
 */
class Header
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Header();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Header();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header(
            const Header& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header(
            Header&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header& operator =(
            const Header& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header& operator =(
            Header&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Header object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Header& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Header object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Header& x) const;

    /*!
     * @brief This function sets a value in member id
     * @param _id New value for member id
     */
    eProsima_user_DllExport void id(
            uint32_t _id);

    /*!
     * @brief This function returns the value of member id
     * @return Value of member id
     */
    eProsima_user_DllExport uint32_t id() const;

    /*!
     * @brief This function returns a reference to member id
     * @return Reference to member id
     */
    eProsima_user_DllExport uint32_t& id();

    /*!
     * @brief This function sets a value in member timeOcc
     * @param _timeOcc New value for member timeOcc
     */
    eProsima_user_DllExport void timeOcc(
            int64_t _timeOcc);

    /*!
     * @brief This function returns the value of member timeOcc
     * @return Value of member timeOcc
     */
    eProsima_user_DllExport int64_t timeOcc() const;

    /*!
     * @brief This function returns a reference to member timeOcc
     * @return Reference to member timeOcc
     */
    eProsima_user_DllExport int64_t& timeOcc();

    /*!
     * @brief This function sets a value in member timeRec
     * @param _timeRec New value for member timeRec
     */
    eProsima_user_DllExport void timeRec(
            int64_t _timeRec);

    /*!
     * @brief This function returns the value of member timeRec
     * @return Value of member timeRec
     */
    eProsima_user_DllExport int64_t timeRec() const;

    /*!
     * @brief This function returns a reference to member timeRec
     * @return Reference to member timeRec
     */
    eProsima_user_DllExport int64_t& timeRec();

    /*!
     * @brief This function sets a value in member timeSent
     * @param _timeSent New value for member timeSent
     */
    eProsima_user_DllExport void timeSent(
            int64_t _timeSent);

    /*!
     * @brief This function returns the value of member timeSent
     * @return Value of member timeSent
     */
    eProsima_user_DllExport int64_t timeSent() const;

    /*!
     * @brief This function returns a reference to member timeSent
     * @return Reference to member timeSent
     */
    eProsima_user_DllExport int64_t& timeSent();


    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const Header& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    uint32_t m_id;
    int64_t m_timeOcc;
    int64_t m_timeRec;
    int64_t m_timeSent;
};

#endif // _FAST_DDS_GENERATED_HEADER_H_