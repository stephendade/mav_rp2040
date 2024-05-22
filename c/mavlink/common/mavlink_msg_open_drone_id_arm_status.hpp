// MESSAGE OPEN_DRONE_ID_ARM_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief OPEN_DRONE_ID_ARM_STATUS message
 *
 * Status from the transmitter telling the flight controller if the remote ID system is ready for arming.
 */
struct OPEN_DRONE_ID_ARM_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 12918;
    static constexpr size_t LENGTH = 51;
    static constexpr size_t MIN_LENGTH = 51;
    static constexpr uint8_t CRC_EXTRA = 139;
    static constexpr auto NAME = "OPEN_DRONE_ID_ARM_STATUS";


    uint8_t status; /*<  Status level indicating if arming is allowed. */
    std::array<char, 50> error; /*<  Text error message, should be empty if status is good to arm. Fill with nulls in unused portion. */


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
        ss << "  status: " << +status << std::endl;
        ss << "  error: \"" << to_string(error) << "\"" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << status;                        // offset: 0
        map << error;                         // offset: 1
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> status;                        // offset: 0
        map >> error;                         // offset: 1
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
