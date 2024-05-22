// MESSAGE MISSION_CURRENT support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief MISSION_CURRENT message
 *
 * Message that announces the sequence number of the current active mission item. The MAV will fly towards this mission item.
 */
struct MISSION_CURRENT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 42;
    static constexpr size_t LENGTH = 6;
    static constexpr size_t MIN_LENGTH = 2;
    static constexpr uint8_t CRC_EXTRA = 28;
    static constexpr auto NAME = "MISSION_CURRENT";


    uint16_t seq; /*<  Sequence */
    uint16_t total; /*<  Total number of mission items on vehicle (on last item, sequence == total). If the autopilot stores its home location as part of the mission this will be excluded from the total. 0: Not supported, UINT16_MAX if no mission is present on the vehicle. */
    uint8_t mission_state; /*<  Mission state machine state. MISSION_STATE_UNKNOWN if state reporting not supported. */
    uint8_t mission_mode; /*<  Vehicle is in a mode that can execute mission items or suspended. 0: Unknown, 1: In mission mode, 2: Suspended (not in mission mode). */


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
        ss << "  seq: " << seq << std::endl;
        ss << "  total: " << total << std::endl;
        ss << "  mission_state: " << +mission_state << std::endl;
        ss << "  mission_mode: " << +mission_mode << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << seq;                           // offset: 0
        map << total;                         // offset: 2
        map << mission_state;                 // offset: 4
        map << mission_mode;                  // offset: 5
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> seq;                           // offset: 0
        map >> total;                         // offset: 2
        map >> mission_state;                 // offset: 4
        map >> mission_mode;                  // offset: 5
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
