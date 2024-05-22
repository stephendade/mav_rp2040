/** @file
 *	@brief MAVLink comm testsuite protocol generated from loweheiser.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "loweheiser.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(loweheiser, LOWEHEISER_GOV_EFI)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::loweheiser::msg::LOWEHEISER_GOV_EFI packet_in{};
    packet_in.volt_batt = 17.0;
    packet_in.curr_batt = 45.0;
    packet_in.curr_gen = 73.0;
    packet_in.curr_rot = 101.0;
    packet_in.fuel_level = 129.0;
    packet_in.throttle = 157.0;
    packet_in.runtime = 963498712;
    packet_in.until_maintenance = 963498920;
    packet_in.rectifier_temp = 241.0;
    packet_in.generator_temp = 269.0;
    packet_in.efi_batt = 297.0;
    packet_in.efi_rpm = 325.0;
    packet_in.efi_pw = 353.0;
    packet_in.efi_fuel_flow = 381.0;
    packet_in.efi_fuel_consumed = 409.0;
    packet_in.efi_baro = 437.0;
    packet_in.efi_mat = 465.0;
    packet_in.efi_clt = 493.0;
    packet_in.efi_tps = 521.0;
    packet_in.efi_exhaust_gas_temperature = 549.0;
    packet_in.efi_index = 1;
    packet_in.generator_status = 21395;
    packet_in.efi_status = 21499;

    mavlink::loweheiser::msg::LOWEHEISER_GOV_EFI packet1{};
    mavlink::loweheiser::msg::LOWEHEISER_GOV_EFI packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.volt_batt, packet2.volt_batt);
    EXPECT_EQ(packet1.curr_batt, packet2.curr_batt);
    EXPECT_EQ(packet1.curr_gen, packet2.curr_gen);
    EXPECT_EQ(packet1.curr_rot, packet2.curr_rot);
    EXPECT_EQ(packet1.fuel_level, packet2.fuel_level);
    EXPECT_EQ(packet1.throttle, packet2.throttle);
    EXPECT_EQ(packet1.runtime, packet2.runtime);
    EXPECT_EQ(packet1.until_maintenance, packet2.until_maintenance);
    EXPECT_EQ(packet1.rectifier_temp, packet2.rectifier_temp);
    EXPECT_EQ(packet1.generator_temp, packet2.generator_temp);
    EXPECT_EQ(packet1.efi_batt, packet2.efi_batt);
    EXPECT_EQ(packet1.efi_rpm, packet2.efi_rpm);
    EXPECT_EQ(packet1.efi_pw, packet2.efi_pw);
    EXPECT_EQ(packet1.efi_fuel_flow, packet2.efi_fuel_flow);
    EXPECT_EQ(packet1.efi_fuel_consumed, packet2.efi_fuel_consumed);
    EXPECT_EQ(packet1.efi_baro, packet2.efi_baro);
    EXPECT_EQ(packet1.efi_mat, packet2.efi_mat);
    EXPECT_EQ(packet1.efi_clt, packet2.efi_clt);
    EXPECT_EQ(packet1.efi_tps, packet2.efi_tps);
    EXPECT_EQ(packet1.efi_exhaust_gas_temperature, packet2.efi_exhaust_gas_temperature);
    EXPECT_EQ(packet1.efi_index, packet2.efi_index);
    EXPECT_EQ(packet1.generator_status, packet2.generator_status);
    EXPECT_EQ(packet1.efi_status, packet2.efi_status);
}

#ifdef TEST_INTEROP
TEST(loweheiser_interop, LOWEHEISER_GOV_EFI)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_loweheiser_gov_efi_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 963498712, 963498920, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 21395, 21499, 1
    };

    mavlink::loweheiser::msg::LOWEHEISER_GOV_EFI packet_in{};
    packet_in.volt_batt = 17.0;
    packet_in.curr_batt = 45.0;
    packet_in.curr_gen = 73.0;
    packet_in.curr_rot = 101.0;
    packet_in.fuel_level = 129.0;
    packet_in.throttle = 157.0;
    packet_in.runtime = 963498712;
    packet_in.until_maintenance = 963498920;
    packet_in.rectifier_temp = 241.0;
    packet_in.generator_temp = 269.0;
    packet_in.efi_batt = 297.0;
    packet_in.efi_rpm = 325.0;
    packet_in.efi_pw = 353.0;
    packet_in.efi_fuel_flow = 381.0;
    packet_in.efi_fuel_consumed = 409.0;
    packet_in.efi_baro = 437.0;
    packet_in.efi_mat = 465.0;
    packet_in.efi_clt = 493.0;
    packet_in.efi_tps = 521.0;
    packet_in.efi_exhaust_gas_temperature = 549.0;
    packet_in.efi_index = 1;
    packet_in.generator_status = 21395;
    packet_in.efi_status = 21499;

    mavlink::loweheiser::msg::LOWEHEISER_GOV_EFI packet2{};

    mavlink_msg_loweheiser_gov_efi_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.volt_batt, packet2.volt_batt);
    EXPECT_EQ(packet_in.curr_batt, packet2.curr_batt);
    EXPECT_EQ(packet_in.curr_gen, packet2.curr_gen);
    EXPECT_EQ(packet_in.curr_rot, packet2.curr_rot);
    EXPECT_EQ(packet_in.fuel_level, packet2.fuel_level);
    EXPECT_EQ(packet_in.throttle, packet2.throttle);
    EXPECT_EQ(packet_in.runtime, packet2.runtime);
    EXPECT_EQ(packet_in.until_maintenance, packet2.until_maintenance);
    EXPECT_EQ(packet_in.rectifier_temp, packet2.rectifier_temp);
    EXPECT_EQ(packet_in.generator_temp, packet2.generator_temp);
    EXPECT_EQ(packet_in.efi_batt, packet2.efi_batt);
    EXPECT_EQ(packet_in.efi_rpm, packet2.efi_rpm);
    EXPECT_EQ(packet_in.efi_pw, packet2.efi_pw);
    EXPECT_EQ(packet_in.efi_fuel_flow, packet2.efi_fuel_flow);
    EXPECT_EQ(packet_in.efi_fuel_consumed, packet2.efi_fuel_consumed);
    EXPECT_EQ(packet_in.efi_baro, packet2.efi_baro);
    EXPECT_EQ(packet_in.efi_mat, packet2.efi_mat);
    EXPECT_EQ(packet_in.efi_clt, packet2.efi_clt);
    EXPECT_EQ(packet_in.efi_tps, packet2.efi_tps);
    EXPECT_EQ(packet_in.efi_exhaust_gas_temperature, packet2.efi_exhaust_gas_temperature);
    EXPECT_EQ(packet_in.efi_index, packet2.efi_index);
    EXPECT_EQ(packet_in.generator_status, packet2.generator_status);
    EXPECT_EQ(packet_in.efi_status, packet2.efi_status);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
