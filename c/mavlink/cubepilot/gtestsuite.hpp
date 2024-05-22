/** @file
 *	@brief MAVLink comm testsuite protocol generated from cubepilot.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "cubepilot.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(cubepilot, CUBEPILOT_RAW_RC)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::cubepilot::msg::CUBEPILOT_RAW_RC packet_in{};
    packet_in.rc_raw = {{ 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 }};

    mavlink::cubepilot::msg::CUBEPILOT_RAW_RC packet1{};
    mavlink::cubepilot::msg::CUBEPILOT_RAW_RC packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.rc_raw, packet2.rc_raw);
}

#ifdef TEST_INTEROP
TEST(cubepilot_interop, CUBEPILOT_RAW_RC)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_cubepilot_raw_rc_t packet_c {
         { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 }
    };

    mavlink::cubepilot::msg::CUBEPILOT_RAW_RC packet_in{};
    packet_in.rc_raw = {{ 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 }};

    mavlink::cubepilot::msg::CUBEPILOT_RAW_RC packet2{};

    mavlink_msg_cubepilot_raw_rc_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.rc_raw, packet2.rc_raw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(cubepilot, HERELINK_VIDEO_STREAM_INFORMATION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::cubepilot::msg::HERELINK_VIDEO_STREAM_INFORMATION packet_in{};
    packet_in.camera_id = 175;
    packet_in.status = 242;
    packet_in.framerate = 17.0;
    packet_in.resolution_h = 17651;
    packet_in.resolution_v = 17755;
    packet_in.bitrate = 963497672;
    packet_in.rotation = 17859;
    packet_in.uri = to_char_array("QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK");

    mavlink::cubepilot::msg::HERELINK_VIDEO_STREAM_INFORMATION packet1{};
    mavlink::cubepilot::msg::HERELINK_VIDEO_STREAM_INFORMATION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.camera_id, packet2.camera_id);
    EXPECT_EQ(packet1.status, packet2.status);
    EXPECT_EQ(packet1.framerate, packet2.framerate);
    EXPECT_EQ(packet1.resolution_h, packet2.resolution_h);
    EXPECT_EQ(packet1.resolution_v, packet2.resolution_v);
    EXPECT_EQ(packet1.bitrate, packet2.bitrate);
    EXPECT_EQ(packet1.rotation, packet2.rotation);
    EXPECT_EQ(packet1.uri, packet2.uri);
}

#ifdef TEST_INTEROP
TEST(cubepilot_interop, HERELINK_VIDEO_STREAM_INFORMATION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_herelink_video_stream_information_t packet_c {
         17.0, 963497672, 17651, 17755, 17859, 175, 242, "QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK"
    };

    mavlink::cubepilot::msg::HERELINK_VIDEO_STREAM_INFORMATION packet_in{};
    packet_in.camera_id = 175;
    packet_in.status = 242;
    packet_in.framerate = 17.0;
    packet_in.resolution_h = 17651;
    packet_in.resolution_v = 17755;
    packet_in.bitrate = 963497672;
    packet_in.rotation = 17859;
    packet_in.uri = to_char_array("QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK");

    mavlink::cubepilot::msg::HERELINK_VIDEO_STREAM_INFORMATION packet2{};

    mavlink_msg_herelink_video_stream_information_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.camera_id, packet2.camera_id);
    EXPECT_EQ(packet_in.status, packet2.status);
    EXPECT_EQ(packet_in.framerate, packet2.framerate);
    EXPECT_EQ(packet_in.resolution_h, packet2.resolution_h);
    EXPECT_EQ(packet_in.resolution_v, packet2.resolution_v);
    EXPECT_EQ(packet_in.bitrate, packet2.bitrate);
    EXPECT_EQ(packet_in.rotation, packet2.rotation);
    EXPECT_EQ(packet_in.uri, packet2.uri);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(cubepilot, HERELINK_TELEM)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::cubepilot::msg::HERELINK_TELEM packet_in{};
    packet_in.rssi = 187;
    packet_in.snr = 17859;
    packet_in.rf_freq = 963497464;
    packet_in.link_bw = 963497672;
    packet_in.link_rate = 963497880;
    packet_in.cpu_temp = 17963;
    packet_in.board_temp = 18067;

    mavlink::cubepilot::msg::HERELINK_TELEM packet1{};
    mavlink::cubepilot::msg::HERELINK_TELEM packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.rssi, packet2.rssi);
    EXPECT_EQ(packet1.snr, packet2.snr);
    EXPECT_EQ(packet1.rf_freq, packet2.rf_freq);
    EXPECT_EQ(packet1.link_bw, packet2.link_bw);
    EXPECT_EQ(packet1.link_rate, packet2.link_rate);
    EXPECT_EQ(packet1.cpu_temp, packet2.cpu_temp);
    EXPECT_EQ(packet1.board_temp, packet2.board_temp);
}

#ifdef TEST_INTEROP
TEST(cubepilot_interop, HERELINK_TELEM)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_herelink_telem_t packet_c {
         963497464, 963497672, 963497880, 17859, 17963, 18067, 187
    };

    mavlink::cubepilot::msg::HERELINK_TELEM packet_in{};
    packet_in.rssi = 187;
    packet_in.snr = 17859;
    packet_in.rf_freq = 963497464;
    packet_in.link_bw = 963497672;
    packet_in.link_rate = 963497880;
    packet_in.cpu_temp = 17963;
    packet_in.board_temp = 18067;

    mavlink::cubepilot::msg::HERELINK_TELEM packet2{};

    mavlink_msg_herelink_telem_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.rssi, packet2.rssi);
    EXPECT_EQ(packet_in.snr, packet2.snr);
    EXPECT_EQ(packet_in.rf_freq, packet2.rf_freq);
    EXPECT_EQ(packet_in.link_bw, packet2.link_bw);
    EXPECT_EQ(packet_in.link_rate, packet2.link_rate);
    EXPECT_EQ(packet_in.cpu_temp, packet2.cpu_temp);
    EXPECT_EQ(packet_in.board_temp, packet2.board_temp);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(cubepilot, CUBEPILOT_FIRMWARE_UPDATE_START)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_START packet_in{};
    packet_in.target_system = 29;
    packet_in.target_component = 96;
    packet_in.size = 963497464;
    packet_in.crc = 963497672;

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_START packet1{};
    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_START packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.size, packet2.size);
    EXPECT_EQ(packet1.crc, packet2.crc);
}

#ifdef TEST_INTEROP
TEST(cubepilot_interop, CUBEPILOT_FIRMWARE_UPDATE_START)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_cubepilot_firmware_update_start_t packet_c {
         963497464, 963497672, 29, 96
    };

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_START packet_in{};
    packet_in.target_system = 29;
    packet_in.target_component = 96;
    packet_in.size = 963497464;
    packet_in.crc = 963497672;

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_START packet2{};

    mavlink_msg_cubepilot_firmware_update_start_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.size, packet2.size);
    EXPECT_EQ(packet_in.crc, packet2.crc);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(cubepilot, CUBEPILOT_FIRMWARE_UPDATE_RESP)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_RESP packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.offset = 963497464;

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_RESP packet1{};
    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_RESP packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.offset, packet2.offset);
}

#ifdef TEST_INTEROP
TEST(cubepilot_interop, CUBEPILOT_FIRMWARE_UPDATE_RESP)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_cubepilot_firmware_update_resp_t packet_c {
         963497464, 17, 84
    };

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_RESP packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.offset = 963497464;

    mavlink::cubepilot::msg::CUBEPILOT_FIRMWARE_UPDATE_RESP packet2{};

    mavlink_msg_cubepilot_firmware_update_resp_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.offset, packet2.offset);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
