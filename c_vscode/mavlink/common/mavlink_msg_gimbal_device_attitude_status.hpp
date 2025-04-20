// MESSAGE GIMBAL_DEVICE_ATTITUDE_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief GIMBAL_DEVICE_ATTITUDE_STATUS message
 *
 * Message reporting the status of a gimbal device.
	  This message should be broadcast by a gimbal device component at a low regular rate (e.g. 5 Hz).
	  For the angles encoded in the quaternion and the angular velocities holds:
	  If the flag GIMBAL_DEVICE_FLAGS_YAW_IN_VEHICLE_FRAME is set, then they are relative to the vehicle heading (vehicle frame).
	  If the flag GIMBAL_DEVICE_FLAGS_YAW_IN_EARTH_FRAME is set, then they are relative to absolute North (earth frame).
	  If neither of these flags are set, then (for backwards compatibility) it holds:
	  If the flag GIMBAL_DEVICE_FLAGS_YAW_LOCK is set, then they are relative to absolute North (earth frame),
	  else they are relative to the vehicle heading (vehicle frame).
	  Other conditions of the flags are not allowed.
	  The quaternion and angular velocities in the other frame can be calculated from delta_yaw and delta_yaw_velocity as
	  q_earth = q_delta_yaw * q_vehicle and w_earth = w_delta_yaw_velocity + w_vehicle (if not NaN).
	  If neither the GIMBAL_DEVICE_FLAGS_YAW_IN_VEHICLE_FRAME nor the GIMBAL_DEVICE_FLAGS_YAW_IN_EARTH_FRAME flag is set,
	  then (for backwards compatibility) the data in the delta_yaw and delta_yaw_velocity fields are to be ignored.
	  New implementations should always set either GIMBAL_DEVICE_FLAGS_YAW_IN_VEHICLE_FRAME or GIMBAL_DEVICE_FLAGS_YAW_IN_EARTH_FRAME,
	  and always should set delta_yaw and delta_yaw_velocity either to the proper value or NaN.
 */
struct GIMBAL_DEVICE_ATTITUDE_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 285;
    static constexpr size_t LENGTH = 49;
    static constexpr size_t MIN_LENGTH = 40;
    static constexpr uint8_t CRC_EXTRA = 137;
    static constexpr auto NAME = "GIMBAL_DEVICE_ATTITUDE_STATUS";


    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID */
    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    uint16_t flags; /*<  Current gimbal flags set. */
    std::array<float, 4> q; /*<  Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation). The frame is described in the message description. */
    float angular_velocity_x; /*< [rad/s] X component of angular velocity (positive: rolling to the right). The frame is described in the message description. NaN if unknown. */
    float angular_velocity_y; /*< [rad/s] Y component of angular velocity (positive: pitching up). The frame is described in the message description. NaN if unknown. */
    float angular_velocity_z; /*< [rad/s] Z component of angular velocity (positive: yawing to the right). The frame is described in the message description. NaN if unknown. */
    uint32_t failure_flags; /*<  Failure flags (0 for no failure) */
    float delta_yaw; /*< [rad] Yaw angle relating the quaternions in earth and body frames (see message description). NaN if unknown. */
    float delta_yaw_velocity; /*< [rad/s] Yaw angular velocity relating the angular velocities in earth and body frames (see message description). NaN if unknown. */
    uint8_t gimbal_device_id; /*<  This field is to be used if the gimbal manager and the gimbal device are the same component and hence have the same component ID. This field is then set a number between 1-6. If the component ID is separate, this field is not required and must be set to 0. */


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
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  flags: " << flags << std::endl;
        ss << "  q: [" << to_string(q) << "]" << std::endl;
        ss << "  angular_velocity_x: " << angular_velocity_x << std::endl;
        ss << "  angular_velocity_y: " << angular_velocity_y << std::endl;
        ss << "  angular_velocity_z: " << angular_velocity_z << std::endl;
        ss << "  failure_flags: " << failure_flags << std::endl;
        ss << "  delta_yaw: " << delta_yaw << std::endl;
        ss << "  delta_yaw_velocity: " << delta_yaw_velocity << std::endl;
        ss << "  gimbal_device_id: " << +gimbal_device_id << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << q;                             // offset: 4
        map << angular_velocity_x;            // offset: 20
        map << angular_velocity_y;            // offset: 24
        map << angular_velocity_z;            // offset: 28
        map << failure_flags;                 // offset: 32
        map << flags;                         // offset: 36
        map << target_system;                 // offset: 38
        map << target_component;              // offset: 39
        map << delta_yaw;                     // offset: 40
        map << delta_yaw_velocity;            // offset: 44
        map << gimbal_device_id;              // offset: 48
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> q;                             // offset: 4
        map >> angular_velocity_x;            // offset: 20
        map >> angular_velocity_y;            // offset: 24
        map >> angular_velocity_z;            // offset: 28
        map >> failure_flags;                 // offset: 32
        map >> flags;                         // offset: 36
        map >> target_system;                 // offset: 38
        map >> target_component;              // offset: 39
        map >> delta_yaw;                     // offset: 40
        map >> delta_yaw_velocity;            // offset: 44
        map >> gimbal_device_id;              // offset: 48
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
