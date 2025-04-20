// MESSAGE CUBEPILOT_RAW_RC support class

#pragma once

namespace mavlink {
namespace cubepilot {
namespace msg {

/**
 * @brief CUBEPILOT_RAW_RC message
 *
 * Raw RC Data
 */
struct CUBEPILOT_RAW_RC : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50001;
    static constexpr size_t LENGTH = 32;
    static constexpr size_t MIN_LENGTH = 32;
    static constexpr uint8_t CRC_EXTRA = 246;
    static constexpr auto NAME = "CUBEPILOT_RAW_RC";


    std::array<uint8_t, 32> rc_raw; /*<   */


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
        ss << "  rc_raw: [" << to_string(rc_raw) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << rc_raw;                        // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> rc_raw;                        // offset: 0
    }
};

} // namespace msg
} // namespace cubepilot
} // namespace mavlink
