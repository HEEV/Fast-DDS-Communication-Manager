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
 * @file engineTemp.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_ENGINETEMP_H_
#define _FAST_DDS_GENERATED_ENGINETEMP_H_

#include "header.h"

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
#if defined(engineTemp_SOURCE)
#define engineTemp_DllAPI __declspec( dllexport )
#else
#define engineTemp_DllAPI __declspec( dllimport )
#endif // engineTemp_SOURCE
#else
#define engineTemp_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define engineTemp_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure EngineTemp defined by the user in the IDL file.
 * @ingroup ENGINETEMP
 */
class EngineTemp
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport EngineTemp();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~EngineTemp();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object EngineTemp that will be copied.
     */
    eProsima_user_DllExport EngineTemp(
            const EngineTemp& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object EngineTemp that will be copied.
     */
    eProsima_user_DllExport EngineTemp(
            EngineTemp&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object EngineTemp that will be copied.
     */
    eProsima_user_DllExport EngineTemp& operator =(
            const EngineTemp& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object EngineTemp that will be copied.
     */
    eProsima_user_DllExport EngineTemp& operator =(
            EngineTemp&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x EngineTemp object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const EngineTemp& x) const;

    /*!
     * @brief Comparison operator.
     * @param x EngineTemp object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const EngineTemp& x) const;

    /*!
     * @brief This function copies the value in member head
     * @param _head New value to be copied in member head
     */
    eProsima_user_DllExport void head(
            const Header& _head);

    /*!
     * @brief This function moves the value in member head
     * @param _head New value to be moved in member head
     */
    eProsima_user_DllExport void head(
            Header&& _head);

    /*!
     * @brief This function returns a constant reference to member head
     * @return Constant reference to member head
     */
    eProsima_user_DllExport const Header& head() const;

    /*!
     * @brief This function returns a reference to member head
     * @return Reference to member head
     */
    eProsima_user_DllExport Header& head();
    /*!
     * @brief This function sets a value in member temp
     * @param _temp New value for member temp
     */
    eProsima_user_DllExport void temp(
            float _temp);

    /*!
     * @brief This function returns the value of member temp
     * @return Value of member temp
     */
    eProsima_user_DllExport float temp() const;

    /*!
     * @brief This function returns a reference to member temp
     * @return Reference to member temp
     */
    eProsima_user_DllExport float& temp();


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
            const EngineTemp& data,
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

    Header m_head;
    float m_temp;
};

#endif // _FAST_DDS_GENERATED_ENGINETEMP_H_