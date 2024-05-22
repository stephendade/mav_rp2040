// MESSAGE SECURE_COMMAND_REPLY support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief SECURE_COMMAND_REPLY message
 *
 * Reply from secure command.
 */
struct SECURE_COMMAND_REPLY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11005;
    static constexpr size_t LENGTH = 230;
    static constexpr size_t MIN_LENGTH = 230;
    static constexpr uint8_t CRC_EXTRA = 93;
    static constexpr auto NAME = "SECURE_COMMAND_REPLY";


    uint32_t sequence; /*<  Sequence ID from request. */
    uint32_t operation; /*<  Operation that was requested. */
    uint8_t result; /*<  Result of command. */
    uint8_t data_length; /*<  Data length. */
    std::array<uint8_t, 220> data; /*<  Reply data. */


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
        ss << "  sequence: " << sequence << std::endl;
        ss << "  operation: " << operation << std::endl;
        ss << "  result: " << +result << std::endl;
        ss << "  data_length: " << +data_length << std::endl;
        ss << "  data: [" << to_string(data) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << sequence;                      // offset: 0
        map << operation;                     // offset: 4
        map << result;                        // offset: 8
        map << data_length;                   // offset: 9
        map << data;                          // offset: 10
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> sequence;                      // offset: 0
        map >> operation;                     // offset: 4
        map >> result;                        // offset: 8
        map >> data_length;                   // offset: 9
        map >> data;                          // offset: 10
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink
