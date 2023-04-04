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
 * @file raceInstructions.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_RACEINSTRUCTIONS_H_
#define _FAST_DDS_GENERATED_RACEINSTRUCTIONS_H_

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
#if defined(raceInstructions_SOURCE)
#define raceInstructions_DllAPI __declspec( dllexport )
#else
#define raceInstructions_DllAPI __declspec( dllimport )
#endif // raceInstructions_SOURCE
#else
#define raceInstructions_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define raceInstructions_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the enumeration Instruction defined by the user in the IDL file.
 * @ingroup RACEINSTRUCTIONS
 */
enum Instruction : uint32_t
{
    START_RACE,
    END_RACE,
    STOP_COLLECTION,
    CONFIRM_RECIEVED
};
/*!
 * @brief This class represents the structure RaceInstructions defined by the user in the IDL file.
 * @ingroup RACEINSTRUCTIONS
 */
class RaceInstructions
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport RaceInstructions();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~RaceInstructions();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object RaceInstructions that will be copied.
     */
    eProsima_user_DllExport RaceInstructions(
            const RaceInstructions& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object RaceInstructions that will be copied.
     */
    eProsima_user_DllExport RaceInstructions(
            RaceInstructions&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object RaceInstructions that will be copied.
     */
    eProsima_user_DllExport RaceInstructions& operator =(
            const RaceInstructions& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object RaceInstructions that will be copied.
     */
    eProsima_user_DllExport RaceInstructions& operator =(
            RaceInstructions&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x RaceInstructions object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const RaceInstructions& x) const;

    /*!
     * @brief Comparison operator.
     * @param x RaceInstructions object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const RaceInstructions& x) const;

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
     * @brief This function sets a value in member inst
     * @param _inst New value for member inst
     */
    eProsima_user_DllExport void inst(
            Instruction _inst);

    /*!
     * @brief This function returns the value of member inst
     * @return Value of member inst
     */
    eProsima_user_DllExport Instruction inst() const;

    /*!
     * @brief This function returns a reference to member inst
     * @return Reference to member inst
     */
    eProsima_user_DllExport Instruction& inst();


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
            const RaceInstructions& data,
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
    Instruction m_inst;
};

#endif // _FAST_DDS_GENERATED_RACEINSTRUCTIONS_H_