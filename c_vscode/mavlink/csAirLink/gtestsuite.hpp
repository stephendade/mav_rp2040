/** @file
 *	@brief MAVLink comm testsuite protocol generated from csAirLink.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "csAirLink.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(csAirLink, AIRLINK_AUTH)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_AUTH packet_in{};
    packet_in.login = to_char_array("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW");
    packet_in.password = to_char_array("YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTU");

    mavlink::csAirLink::msg::AIRLINK_AUTH packet1{};
    mavlink::csAirLink::msg::AIRLINK_AUTH packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.login, packet2.login);
    EXPECT_EQ(packet1.password, packet2.password);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_AUTH)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_auth_t packet_c {
         "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW", "YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTU"
    };

    mavlink::csAirLink::msg::AIRLINK_AUTH packet_in{};
    packet_in.login = to_char_array("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW");
    packet_in.password = to_char_array("YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTU");

    mavlink::csAirLink::msg::AIRLINK_AUTH packet2{};

    mavlink_msg_airlink_auth_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.login, packet2.login);
    EXPECT_EQ(packet_in.password, packet2.password);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(csAirLink, AIRLINK_AUTH_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet1{};
    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.resp_type, packet2.resp_type);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_AUTH_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_auth_response_t packet_c {
         5
    };

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet2{};

    mavlink_msg_airlink_auth_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.resp_type, packet2.resp_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
