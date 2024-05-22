// MESSAGE CUBEPILOT_FIRMWARE_UPDATE_START support class

#pragma once

namespace mavlink {
namespace cubepilot {
namespace msg {

/**
 * @brief CUBEPILOT_FIRMWARE_UPDATE_START message
 *
 * Start firmware update with encapsulated data.
 */
struct CUBEPILOT_FIRMWARE_UPDATE_START : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50004;
    static constexpr size_t LENGTH = 10;
    static constexpr size_t MIN_LENGTH = 10;
    static constexpr uint8_t CRC_EXTRA = 240;
    static constexpr auto NAME = "CUBEPILOT_FIRMWARE_UPDATE_START";


    uint8_t target_system; /*<  System ID. */
    uint8_t target_component; /*<  Component ID. */
    uint32_t size; /*< [bytes] FW Size. */
    uint32_t crc; /*<  FW CRC. */


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
        ss << "  size: " << size << std::endl;
        ss << "  crc: " << crc << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << size;                          // offset: 0
        map << crc;                           // offset: 4
        map << target_system;                 // offset: 8
        map << target_component;              // offset: 9
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> size;                          // offset: 0
        map >> crc;                           // offset: 4
        map >> target_system;                 // offset: 8
        map >> target_component;              // offset: 9
    }
};

} // namespace msg
} // namespace cubepilot
} // namespace mavlink
