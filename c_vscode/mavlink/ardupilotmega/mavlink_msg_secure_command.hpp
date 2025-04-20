// MESSAGE SECURE_COMMAND support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief SECURE_COMMAND message
 *
 * Send a secure command. Data should be signed with a private key corresponding with a public key known to the recipient. Signature should be over the concatenation of the sequence number (little-endian format), the operation (little-endian format) the data and the session key. For SECURE_COMMAND_GET_SESSION_KEY the session key should be zero length. The data array consists of the data followed by the signature. The sum of the data_length and the sig_length cannot be more than 220. The format of the data is command specific.
 */
struct SECURE_COMMAND : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11004;
    static constexpr size_t LENGTH = 232;
    static constexpr size_t MIN_LENGTH = 232;
    static constexpr uint8_t CRC_EXTRA = 11;
    static constexpr auto NAME = "SECURE_COMMAND";


    uint8_t target_system; /*<  System ID. */
    uint8_t target_component; /*<  Component ID. */
    uint32_t sequence; /*<  Sequence ID for tagging reply. */
    uint32_t operation; /*<  Operation being requested. */
    uint8_t data_length; /*<  Data length. */
    uint8_t sig_length; /*<  Signature length. */
    std::array<uint8_t, 220> data; /*<  Signed data. */


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
        ss << "  sequence: " << sequence << std::endl;
        ss << "  operation: " << operation << std::endl;
        ss << "  data_length: " << +data_length << std::endl;
        ss << "  sig_length: " << +sig_length << std::endl;
        ss << "  data: [" << to_string(data) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << sequence;                      // offset: 0
        map << operation;                     // offset: 4
        map << target_system;                 // offset: 8
        map << target_component;              // offset: 9
        map << data_length;                   // offset: 10
        map << sig_length;                    // offset: 11
        map << data;                          // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> sequence;                      // offset: 0
        map >> operation;                     // offset: 4
        map >> target_system;                 // offset: 8
        map >> target_component;              // offset: 9
        map >> data_length;                   // offset: 10
        map >> sig_length;                    // offset: 11
        map >> data;                          // offset: 12
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink
