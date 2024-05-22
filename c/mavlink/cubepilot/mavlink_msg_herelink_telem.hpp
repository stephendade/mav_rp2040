// MESSAGE HERELINK_TELEM support class

#pragma once

namespace mavlink {
namespace cubepilot {
namespace msg {

/**
 * @brief HERELINK_TELEM message
 *
 * Herelink Telemetry
 */
struct HERELINK_TELEM : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50003;
    static constexpr size_t LENGTH = 19;
    static constexpr size_t MIN_LENGTH = 19;
    static constexpr uint8_t CRC_EXTRA = 62;
    static constexpr auto NAME = "HERELINK_TELEM";


    uint8_t rssi; /*<   */
    int16_t snr; /*<   */
    uint32_t rf_freq; /*<   */
    uint32_t link_bw; /*<   */
    uint32_t link_rate; /*<   */
    int16_t cpu_temp; /*<   */
    int16_t board_temp; /*<   */


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
        ss << "  rssi: " << +rssi << std::endl;
        ss << "  snr: " << snr << std::endl;
        ss << "  rf_freq: " << rf_freq << std::endl;
        ss << "  link_bw: " << link_bw << std::endl;
        ss << "  link_rate: " << link_rate << std::endl;
        ss << "  cpu_temp: " << cpu_temp << std::endl;
        ss << "  board_temp: " << board_temp << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << rf_freq;                       // offset: 0
        map << link_bw;                       // offset: 4
        map << link_rate;                     // offset: 8
        map << snr;                           // offset: 12
        map << cpu_temp;                      // offset: 14
        map << board_temp;                    // offset: 16
        map << rssi;                          // offset: 18
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> rf_freq;                       // offset: 0
        map >> link_bw;                       // offset: 4
        map >> link_rate;                     // offset: 8
        map >> snr;                           // offset: 12
        map >> cpu_temp;                      // offset: 14
        map >> board_temp;                    // offset: 16
        map >> rssi;                          // offset: 18
    }
};

} // namespace msg
} // namespace cubepilot
} // namespace mavlink
