// MESSAGE LOWEHEISER_GOV_EFI support class

#pragma once

namespace mavlink {
namespace loweheiser {
namespace msg {

/**
 * @brief LOWEHEISER_GOV_EFI message
 *
 * Composite EFI and Governor data from Loweheiser equipment.  This message is created by the EFI unit based on its own data and data received from a governor attached to that EFI unit.
 */
struct LOWEHEISER_GOV_EFI : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10151;
    static constexpr size_t LENGTH = 85;
    static constexpr size_t MIN_LENGTH = 85;
    static constexpr uint8_t CRC_EXTRA = 195;
    static constexpr auto NAME = "LOWEHEISER_GOV_EFI";


    float volt_batt; /*< [V] Generator Battery voltage. */
    float curr_batt; /*< [A] Generator Battery current. */
    float curr_gen; /*< [A] Current being produced by generator. */
    float curr_rot; /*< [A] Load current being consumed by the UAV (sum of curr_gen and curr_batt) */
    float fuel_level; /*< [l] Generator fuel remaining in litres. */
    float throttle; /*< [%] Throttle Output. */
    uint32_t runtime; /*< [s] Seconds this generator has run since it was rebooted. */
    int32_t until_maintenance; /*< [s] Seconds until this generator requires maintenance.  A negative value indicates maintenance is past due. */
    float rectifier_temp; /*< [degC] The Temperature of the rectifier. */
    float generator_temp; /*< [degC] The temperature of the mechanical motor, fuel cell core or generator. */
    float efi_batt; /*< [V]  EFI Supply Voltage. */
    float efi_rpm; /*< [rpm] Motor RPM. */
    float efi_pw; /*< [ms] Injector pulse-width in miliseconds. */
    float efi_fuel_flow; /*<  Fuel flow rate in litres/hour. */
    float efi_fuel_consumed; /*< [l] Fuel consumed. */
    float efi_baro; /*< [kPa] Atmospheric pressure. */
    float efi_mat; /*< [degC] Manifold Air Temperature. */
    float efi_clt; /*< [degC] Cylinder Head Temperature. */
    float efi_tps; /*< [%] Throttle Position. */
    float efi_exhaust_gas_temperature; /*< [degC] Exhaust gas temperature. */
    uint8_t efi_index; /*<  EFI index. */
    uint16_t generator_status; /*<  Generator status. */
    uint16_t efi_status; /*<  EFI status. */


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
        ss << "  volt_batt: " << volt_batt << std::endl;
        ss << "  curr_batt: " << curr_batt << std::endl;
        ss << "  curr_gen: " << curr_gen << std::endl;
        ss << "  curr_rot: " << curr_rot << std::endl;
        ss << "  fuel_level: " << fuel_level << std::endl;
        ss << "  throttle: " << throttle << std::endl;
        ss << "  runtime: " << runtime << std::endl;
        ss << "  until_maintenance: " << until_maintenance << std::endl;
        ss << "  rectifier_temp: " << rectifier_temp << std::endl;
        ss << "  generator_temp: " << generator_temp << std::endl;
        ss << "  efi_batt: " << efi_batt << std::endl;
        ss << "  efi_rpm: " << efi_rpm << std::endl;
        ss << "  efi_pw: " << efi_pw << std::endl;
        ss << "  efi_fuel_flow: " << efi_fuel_flow << std::endl;
        ss << "  efi_fuel_consumed: " << efi_fuel_consumed << std::endl;
        ss << "  efi_baro: " << efi_baro << std::endl;
        ss << "  efi_mat: " << efi_mat << std::endl;
        ss << "  efi_clt: " << efi_clt << std::endl;
        ss << "  efi_tps: " << efi_tps << std::endl;
        ss << "  efi_exhaust_gas_temperature: " << efi_exhaust_gas_temperature << std::endl;
        ss << "  efi_index: " << +efi_index << std::endl;
        ss << "  generator_status: " << generator_status << std::endl;
        ss << "  efi_status: " << efi_status << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << volt_batt;                     // offset: 0
        map << curr_batt;                     // offset: 4
        map << curr_gen;                      // offset: 8
        map << curr_rot;                      // offset: 12
        map << fuel_level;                    // offset: 16
        map << throttle;                      // offset: 20
        map << runtime;                       // offset: 24
        map << until_maintenance;             // offset: 28
        map << rectifier_temp;                // offset: 32
        map << generator_temp;                // offset: 36
        map << efi_batt;                      // offset: 40
        map << efi_rpm;                       // offset: 44
        map << efi_pw;                        // offset: 48
        map << efi_fuel_flow;                 // offset: 52
        map << efi_fuel_consumed;             // offset: 56
        map << efi_baro;                      // offset: 60
        map << efi_mat;                       // offset: 64
        map << efi_clt;                       // offset: 68
        map << efi_tps;                       // offset: 72
        map << efi_exhaust_gas_temperature;   // offset: 76
        map << generator_status;              // offset: 80
        map << efi_status;                    // offset: 82
        map << efi_index;                     // offset: 84
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> volt_batt;                     // offset: 0
        map >> curr_batt;                     // offset: 4
        map >> curr_gen;                      // offset: 8
        map >> curr_rot;                      // offset: 12
        map >> fuel_level;                    // offset: 16
        map >> throttle;                      // offset: 20
        map >> runtime;                       // offset: 24
        map >> until_maintenance;             // offset: 28
        map >> rectifier_temp;                // offset: 32
        map >> generator_temp;                // offset: 36
        map >> efi_batt;                      // offset: 40
        map >> efi_rpm;                       // offset: 44
        map >> efi_pw;                        // offset: 48
        map >> efi_fuel_flow;                 // offset: 52
        map >> efi_fuel_consumed;             // offset: 56
        map >> efi_baro;                      // offset: 60
        map >> efi_mat;                       // offset: 64
        map >> efi_clt;                       // offset: 68
        map >> efi_tps;                       // offset: 72
        map >> efi_exhaust_gas_temperature;   // offset: 76
        map >> generator_status;              // offset: 80
        map >> efi_status;                    // offset: 82
        map >> efi_index;                     // offset: 84
    }
};

} // namespace msg
} // namespace loweheiser
} // namespace mavlink
