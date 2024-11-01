// Copyright (c) 2021 Juan Miguel Jimeno
// and modified 2024 John Vial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ESP32S3_WIFI_CONFIG_H
#define ESP32S3_WIFI_CONFIG_H

#define LED_PIN LED_BUILTIN //used for debugging status

//uncomment the base you're building
//#define LINO_BASE DIFFERENTIAL_DRIVE       // 2WD and Tracked robot w/ 2 motors
#define LINO_BASE SKID_STEER            // 4WD robot
// #define LINO_BASE MECANUM               // Mecanum drive robot

//uncomment the motor driver you're using

#define USE_BTS7960_MOTOR_DRIVER        // BTS7970 Motor Driver using A4950 (<40V) module or DRV8833 (<10V)

#define K_P 0.6                             // P constant
#define K_I 0.8                             // I constant
#define K_D 0.5                             // D constant

#define ACCEL_COV { 0.01, 0.01, 0.01 }
#define GYRO_COV { 0.001, 0.001, 0.001 }
#define ORI_COV { 0.01, 0.01, 0.01 }
#define MAG_COV { 1e-12, 1e-12, 1e-12 }
#define POSE_COV { 0.001, 0.001, 0.001, 0.001, 0.001, 0.001 }
#define TWIST_COV { 0.001, 0.001, 0.001, 0.003, 0.003, 0.003 }

/*
ROBOT ORIENTATION
         FRONT
    MOTOR1  MOTOR2  (2WD/ACKERMANN)
    MOTOR3  MOTOR4  (4WD/MECANUM)
         BACK
*/

//define your robot' specs here
#define MOTOR_MAX_RPM 150                   // motor's max RPM
#define MAX_RPM_RATIO 0.85                  // max RPM allowed for each MAX_RPM_ALLOWED = MOTOR_MAX_RPM * MAX_RPM_RATIO
#define MOTOR_OPERATING_VOLTAGE 6          // motor's operating voltage (used to calculate max RPM)
#define MOTOR_POWER_MAX_VOLTAGE 5          // max voltage of the motor's power source (used to calculate max RPM)
#define MOTOR_POWER_MEASURED_VOLTAGE 5     // current voltage reading of the power connected to the motor (used for calibration)
#define COUNTS_PER_REV1 1050 //was 450, but it is 7 ticks per motor rev, and 150 speed reduction                 // wheel1 encoder's no of ticks per rev
#define COUNTS_PER_REV2 1050                 // wheel2 encoder's no of ticks per rev
#define COUNTS_PER_REV3 1050                 // wheel3 encoder's no of ticks per rev
#define COUNTS_PER_REV4 1050                // wheel4 encoder's no of ticks per rev
#define WHEEL_DIAMETER 0.040               // wheel's diameter in meters
#define LR_WHEELS_DISTANCE 0.105            // distance between left and right wheels
#define PWM_BITS 10                         // PWM Resolution of the microcontroller
#define PWM_FREQUENCY 200                 // PWM Frequency
#define SERVO_BITS 12                       // Servo PWM resolution
#define SERVO_FREQ 50                       // Servo PWM frequency

// INVERT ENCODER COUNTS
#define MOTOR1_ENCODER_INV false
#define MOTOR2_ENCODER_INV true
#define MOTOR3_ENCODER_INV true
#define MOTOR4_ENCODER_INV false

// INVERT MOTOR DIRECTIONS
#define MOTOR1_INV false
#define MOTOR2_INV true
#define MOTOR3_INV true
#define MOTOR4_INV false

// ENCODER PINS
#define MOTOR1_ENCODER_A 14 //
#define MOTOR1_ENCODER_B 9 //

#define MOTOR2_ENCODER_A 7 //
#define MOTOR2_ENCODER_B 4 //

#define MOTOR3_ENCODER_A 38 //
#define MOTOR3_ENCODER_B 45 //

#define MOTOR4_ENCODER_A 44
#define MOTOR4_ENCODER_B 43 //

// MOTOR PINS

#define MOTOR1_PWM -1 //DON'T TOUCH THIS! This is just a placeholder
#define MOTOR1_IN_A 21 // !
#define MOTOR1_IN_B 39 // !

#define MOTOR2_PWM -1 //DON'T TOUCH THIS! This is just a placeholder
#define MOTOR2_IN_A 16 // !
#define MOTOR2_IN_B 15 //!

#define MOTOR3_PWM -1 //DON'T TOUCH THIS! This is just a placeholder
#define MOTOR3_IN_A 8 //!
#define MOTOR3_IN_B 40 // !

#define MOTOR4_PWM -1 //DON'T TOUCH THIS! This is just a placeholder
#define MOTOR4_IN_A 1 //!
#define MOTOR4_IN_B 2 //!

#define PWM_MAX pow(2, PWM_BITS) - 1
#define PWM_MIN -PWM_MAX


#define AGENT_IP { 192, 168, 1, 119 }  // eg IP of the desktop computer
#define AGENT_PORT 8888
// Enable WiFi with null terminated list of multiple APs SSID and password
#define WIFI_AP_LIST {{"WifiName", "wifi_password"}, , {NULL}}
#define WIFI_MONITOR 2 // min. period to send wifi signal strength to syslog
#define USE_ARDUINO_OTA
#define USE_SYSLOG
#define SYSLOG_SERVER { 192, 168, 1, 119 }  // eg IP of the desktop computer
#define SYSLOG_PORT 514
#define DEVICE_HOSTNAME "esp32s3_wifi"
#define APP_NAME "hardware"
#define USE_LIDAR_UDP
#define LIDAR_RXD 17
#define LIDAR_PWM 18
#define LIDAR_SERIAL 4 // uart number
#define LIDAR_BAUDRATE 230400
#define LIDAR_SERVER { 192, 168, 1, 119 }  // eg IP of the desktop computer
#define LIDAR_PORT 8889
#define BAUDRATE 921600
#define SDA_PIN 8 // specify I2C pins
#define SCL_PIN 9
#define NODE_NAME "esp32s3_wifi"
// #define TOPIC_PREFIX "esp32s3_wifi/"
// #define CONTROL_TIMER 20
// #define BATTERY_TIMER 2000

// battery voltage ADC pin
#define BATTERY_PIN 1
// 3.3V ref, 12 bits ADC, 33k + 10k voltage divider
// #define USE_ADC_LUT
#ifdef USE_ADC_LUT
const int16_t ADC_LUT[4096] = { /* insert adc_calibrate data here */ };
#define BATTERY_ADJUST(v) (ADC_LUT[v] * (3.3 / 4096 * (33 + 10) / 10 * 1.0))
#else
#define BATTERY_ADJUST(v) ((v) * (3.3 / 4096 * (33 + 10) / 10))
#endif
// #define USE_INA219
#define BATTERY_DIP 0.98  // battery voltage drop alert

#define USE_SHORT_BRAKE // for shorter stopping distance

#ifdef USE_SYSLOG
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){ \
    syslog(LOG_ERR, "%s RCCHECK failed %d", __FUNCTION__, temp_rc); \
    return false; }}
#else
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){ \
    flashLED(3); \
    return false; }} // do not block
#endif

#endif
