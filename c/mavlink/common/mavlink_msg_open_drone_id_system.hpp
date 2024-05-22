// MESSAGE OPEN_DRONE_ID_SYSTEM support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief OPEN_DRONE_ID_SYSTEM message
 *
 * Data for filling the OpenDroneID System message. The System Message contains general system information including the operator location/altitude and possible aircraft group and/or category/class information.
 */
struct OPEN_DRONE_ID_SYSTEM : mavlink::Message {
    static constexpr msgid_t MSG_ID = 12904;
    static constexpr size_t LENGTH = 54;
    static constexpr size_t MIN_LENGTH = 54;
    static constexpr uint8_t CRC_EXTRA = 77;
    static constexpr auto NAME = "OPEN_DRONE_ID_SYSTEM";


    uint8_t target_system; /*<  System ID (0 for broadcast). */
    uint8_t target_component; /*<  Component ID (0 for broadcast). */
    std::array<uint8_t, 20> id_or_mac; /*<  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html.  */
    uint8_t operator_location_type; /*<  Specifies the operator location type. */
    uint8_t classification_type; /*<  Specifies the classification type of the UA. */
    int32_t operator_latitude; /*< [degE7] Latitude of the operator. If unknown: 0 (both Lat/Lon). */
    int32_t operator_longitude; /*< [degE7] Longitude of the operator. If unknown: 0 (both Lat/Lon). */
    uint16_t area_count; /*<  Number of aircraft in the area, group or formation (default 1). */
    uint16_t area_radius; /*< [m] Radius of the cylindrical area of the group or formation (default 0). */
    float area_ceiling; /*< [m] Area Operations Ceiling relative to WGS84. If unknown: -1000 m. */
    float area_floor; /*< [m] Area Operations Floor relative to WGS84. If unknown: -1000 m. */
    uint8_t category_eu; /*<  When classification_type is MAV_ODID_CLASSIFICATION_TYPE_EU, specifies the category of the UA. */
    uint8_t class_eu; /*<  When classification_type is MAV_ODID_CLASSIFICATION_TYPE_EU, specifies the class of the UA. */
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
        ss << "  id_or_mac: [" << to_string(id_or_mac) << "]" << std::endl;
        ss << "  operator_location_type: " << +operator_location_type << std::endl;
        ss << "  classification_type: " << +classification_type << std::endl;
        ss << "  operator_latitude: " << operator_latitude << std::endl;
        ss << "  operator_longitude: " << operator_longitude << std::endl;
        ss << "  area_count: " << area_count << std::endl;
        ss << "  area_radius: " << area_radius << std::endl;
        ss << "  area_ceiling: " << area_ceiling << std::endl;
        ss << "  area_floor: " << area_floor << std::endl;
        ss << "  category_eu: " << +category_eu << std::endl;
        ss << "  class_eu: " << +class_eu << std::endl;
        ss << "  operator_altitude_geo: " << operator_altitude_geo << std::endl;
        ss << "  timestamp: " << timestamp << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << operator_latitude;             // offset: 0
        map << operator_longitude;            // offset: 4
        map << area_ceiling;                  // offset: 8
        map << area_floor;                    // offset: 12
        map << operator_altitude_geo;         // offset: 16
        map << timestamp;                     // offset: 20
        map << area_count;                    // offset: 24
        map << area_radius;                   // offset: 26
        map << target_system;                 // offset: 28
        map << target_component;              // offset: 29
        map << id_or_mac;                     // offset: 30
        map << operator_location_type;        // offset: 50
        map << classification_type;           // offset: 51
        map << category_eu;                   // offset: 52
        map << class_eu;                      // offset: 53
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> operator_latitude;             // offset: 0
        map >> operator_longitude;            // offset: 4
        map >> area_ceiling;                  // offset: 8
        map >> area_floor;                    // offset: 12
        map >> operator_altitude_geo;         // offset: 16
        map >> timestamp;                     // offset: 20
        map >> area_count;                    // offset: 24
        map >> area_radius;                   // offset: 26
        map >> target_system;                 // offset: 28
        map >> target_component;              // offset: 29
        map >> id_or_mac;                     // offset: 30
        map >> operator_location_type;        // offset: 50
        map >> classification_type;           // offset: 51
        map >> category_eu;                   // offset: 52
        map >> class_eu;                      // offset: 53
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
