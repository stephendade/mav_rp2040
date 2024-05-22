// MESSAGE CUBEPILOT_FIRMWARE_UPDATE_RESP support class

#pragma once

namespace mavlink {
namespace cubepilot {
namespace msg {

/**
 * @brief CUBEPILOT_FIRMWARE_UPDATE_RESP message
 *
 * offset response to encapsulated data.
 */
struct CUBEPILOT_FIRMWARE_UPDATE_RESP : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50005;
    static constexpr size_t LENGTH = 6;
    static constexpr size_t MIN_LENGTH = 6;
    static constexpr uint8_t CRC_EXTRA = 152;
    static constexpr auto NAME = "CUBEPILOT_FIRMWARE_UPDATE_RESP";


    uint8_t target_system; /*<  System ID. */
    uint8_t target_component; /*<  Component ID. */
    uint32_t offset; /*< [bytes] FW Offset. */


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
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  offset: " << offset << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << offset;                        // offset: 0
        map << target_system;                 // offset: 4
        map << target_component;              // offset: 5
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> offset;                        // offset: 0
        map >> target_system;                 // offset: 4
        map >> target_component;              // offset: 5
    }
};

} // namespace msg
} // namespace cubepilot
} // namespace mavlink
