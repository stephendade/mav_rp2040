// MESSAGE MANUAL_CONTROL support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief MANUAL_CONTROL message
 *
 * This message provides an API for manually controlling the vehicle using standard joystick axes nomenclature, along with a joystick-like input device. Unused axes can be disabled an buttons are also transmit as boolean values of their 
 */
struct MANUAL_CONTROL : mavlink::Message {
    static constexpr msgid_t MSG_ID = 69;
    static constexpr size_t LENGTH = 30;
    static constexpr size_t MIN_LENGTH = 11;
    static constexpr uint8_t CRC_EXTRA = 243;
    static constexpr auto NAME = "MANUAL_CONTROL";


    uint8_t target; /*<  The system to be controlled. */
    int16_t x; /*<  X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle. */
    int16_t y; /*<  Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle. */
    int16_t z; /*<  Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle. Positive values are positive thrust, negative values are negative thrust. */
    int16_t r; /*<  R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle. */
    uint16_t buttons; /*<  A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1. */
    uint16_t buttons2; /*<  A bitfield corresponding to the joystick buttons' 16-31 current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 16. */
    uint8_t enabled_extensions; /*<  Set bits to 1 to indicate which of the following extension fields contain valid data: bit 0: pitch, bit 1: roll, bit 2: aux1, bit 3: aux2, bit 4: aux3, bit 5: aux4, bit 6: aux5, bit 7: aux6 */
    int16_t s; /*<  Pitch-only-axis, normalized to the range [-1000,1000]. Generally corresponds to pitch on vehicles with additional degrees of freedom. Valid if bit 0 of enabled_extensions field is set. Set to 0 if invalid. */
    int16_t t; /*<  Roll-only-axis, normalized to the range [-1000,1000]. Generally corresponds to roll on vehicles with additional degrees of freedom. Valid if bit 1 of enabled_extensions field is set. Set to 0 if invalid. */
    int16_t aux1; /*<  Aux continuous input field 1. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 2 of enabled_extensions field is set. 0 if bit 2 is unset. */
    int16_t aux2; /*<  Aux continuous input field 2. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 3 of enabled_extensions field is set. 0 if bit 3 is unset. */
    int16_t aux3; /*<  Aux continuous input field 3. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 4 of enabled_extensions field is set. 0 if bit 4 is unset. */
    int16_t aux4; /*<  Aux continuous input field 4. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 5 of enabled_extensions field is set. 0 if bit 5 is unset. */
    int16_t aux5; /*<  Aux continuous input field 5. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 6 of enabled_extensions field is set. 0 if bit 6 is unset. */
    int16_t aux6; /*<  Aux continuous input field 6. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 7 of enabled_extensions field is set. 0 if bit 7 is unset. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  target: " << +target << std::endl;
        ss << "  x: " << x << std::endl;
        ss << "  y: " << y << std::endl;
        ss << "  z: " << z << std::endl;
        ss << "  r: " << r << std::endl;
        ss << "  buttons: " << buttons << std::endl;
        ss << "  buttons2: " << buttons2 << std::endl;
        ss << "  enabled_extensions: " << +enabled_extensions << std::endl;
        ss << "  s: " << s << std::endl;
        ss << "  t: " << t << std::endl;
        ss << "  aux1: " << aux1 << std::endl;
        ss << "  aux2: " << aux2 << std::endl;
        ss << "  aux3: " << aux3 << std::endl;
        ss << "  aux4: " << aux4 << std::endl;
        ss << "  aux5: " << aux5 << std::endl;
        ss << "  aux6: " << aux6 << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << x;                             // offset: 0
        map << y;                             // offset: 2
        map << z;                             // offset: 4
        map << r;                             // offset: 6
        map << buttons;                       // offset: 8
        map << target;                        // offset: 10
        map << buttons2;                      // offset: 11
        map << enabled_extensions;            // offset: 13
        map << s;                             // offset: 14
        map << t;                             // offset: 16
        map << aux1;                          // offset: 18
        map << aux2;                          // offset: 20
        map << aux3;                          // offset: 22
        map << aux4;                          // offset: 24
        map << aux5;                          // offset: 26
        map << aux6;                          // offset: 28
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> x;                             // offset: 0
        map >> y;                             // offset: 2
        map >> z;                             // offset: 4
        map >> r;                             // offset: 6
        map >> buttons;                       // offset: 8
        map >> target;                        // offset: 10
        map >> buttons2;                      // offset: 11
        map >> enabled_extensions;            // offset: 13
        map >> s;                             // offset: 14
        map >> t;                             // offset: 16
        map >> aux1;                          // offset: 18
        map >> aux2;                          // offset: 20
        map >> aux3;                          // offset: 22
        map >> aux4;                          // offset: 24
        map >> aux5;                          // offset: 26
        map >> aux6;                          // offset: 28
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
