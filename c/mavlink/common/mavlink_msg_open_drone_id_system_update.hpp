// MESSAGE OPEN_DRONE_ID_SYSTEM_UPDATE support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief OPEN_DRONE_ID_SYSTEM_UPDATE message
 *
 * Update the data in the OPEN_DRONE_ID_SYSTEM message with new location information. This can be sent to update the location information for the operator when no other information in the SYSTEM message has changed. This message allows for efficient operation on radio links which have limited uplink bandwidth while meeting requirements for update frequency of the operator location.
 */
struct OPEN_DRONE_ID_SYSTEM_UPDATE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 12919;
    static constexpr size_t LENGTH = 18;
    static constexpr size_t MIN_LENGTH = 18;
    static constexpr uint8_t CRC_EXTRA = 7;
    static constexpr auto NAME = "OPEN_DRONE_ID_SYSTEM_UPDATE";


    uint8_t target_system; /*<  System ID (0 for broadcast). */
    uint8_t target_component; /*<  Component ID (0 for broadcast). */
    int32_t operator_latitude; /*< [degE7] Latitude of the operator. If unknown: 0 (both Lat/Lon). */
    int32_t operator_longitude; /*< [degE7] Longitude of the operator. If unknown: 0 (both Lat/Lon). */
    float operator_altitude_geo; /*< [m] Geodetic altitude of the operator relative to WGS84. If unknown: -1000 m. */
    uint32_t timestamp; /*< [s] 32 bit Unix Timestamp in seconds since 00:00:00 01/01/2019. */


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
        ss << "  operator_latitude: " << operator_latitude << std::endl;
        ss << "  operator_longitude: " << operator_longitude << std::endl;
        ss << "  operator_altitude_geo: " << operator_altitude_geo << std::endl;
        ss << "  timestamp: " << timestamp << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << operator_latitude;             // offset: 0
        map << operator_longitude;            // offset: 4
        map << operator_altitude_geo;         // offset: 8
        map << timestamp;                     // offset: 12
        map << target_system;                 // offset: 16
        map << target_component;              // offset: 17
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> operator_latitude;             // offset: 0
        map >> operator_longitude;            // offset: 4
        map >> operator_altitude_geo;         // offset: 8
        map >> timestamp;                     // offset: 12
        map >> target_system;                 // offset: 16
        map >> target_component;              // offset: 17
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
