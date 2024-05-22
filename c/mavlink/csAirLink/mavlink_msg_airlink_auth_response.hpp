// MESSAGE AIRLINK_AUTH_RESPONSE support class

#pragma once

namespace mavlink {
namespace csAirLink {
namespace msg {

/**
 * @brief AIRLINK_AUTH_RESPONSE message
 *
 * Response to the authorization request
 */
struct AIRLINK_AUTH_RESPONSE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 52001;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 239;
    static constexpr auto NAME = "AIRLINK_AUTH_RESPONSE";


    uint8_t resp_type; /*<  Response type */


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
        ss << "  resp_type: " << +resp_type << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << resp_type;                     // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> resp_type;                     // offset: 0
    }
};

} // namespace msg
} // namespace csAirLink
} // namespace mavlink
