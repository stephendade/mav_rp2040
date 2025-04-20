// MESSAGE RELAY_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief RELAY_STATUS message
 *
 * Reports the on/off state of relays, as controlled by MAV_CMD_DO_SET_RELAY.
 */
struct RELAY_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 376;
    static constexpr size_t LENGTH = 8;
    static constexpr size_t MIN_LENGTH = 8;
    static constexpr uint8_t CRC_EXTRA = 199;
    static constexpr auto NAME = "RELAY_STATUS";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    uint16_t on; /*<  Relay states.  Relay instance numbers are represented as individual bits in this mask by offset. */
    uint16_t present; /*<  Relay present.  Relay instance numbers are represented as individual bits in this mask by offset.  Bits will be true if a relay instance is configured. */


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
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  on: " << on << std::endl;
        ss << "  present: " << present << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << on;                            // offset: 4
        map << present;                       // offset: 6
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> on;                            // offset: 4
        map >> present;                       // offset: 6
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
