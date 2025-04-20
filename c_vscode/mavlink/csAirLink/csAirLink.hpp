/** @file
 *	@brief MAVLink comm protocol generated from csAirLink.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace csAirLink {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 2> MESSAGE_ENTRIES {{ {52000, 13, 100, 100, 0, 0, 0}, {52001, 239, 1, 1, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 3;


// ENUM DEFINITIONS


/** @brief  */
enum class AIRLINK_AUTH_RESPONSE_TYPE : uint8_t
{
    ERROR_LOGIN_OR_PASS=0, /* Login or password error | */
    OK=1, /* Auth successful | */
};

//! AIRLINK_AUTH_RESPONSE_TYPE ENUM_END
constexpr auto AIRLINK_AUTH_RESPONSE_TYPE_ENUM_END = 2;


} // namespace csAirLink
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_airlink_auth.hpp"
#include "./mavlink_msg_airlink_auth_response.hpp"

// base include

