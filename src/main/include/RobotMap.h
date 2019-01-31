/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
//PWM
constexpr int LEFTMOTOR = 9;
constexpr int RIGHTMOTOR = 8;
constexpr int SHOOTER_WINDOW_MOTOR = 0;
constexpr int SHOOTER_PICKUP_TOP = 0;
constexpr int SHOOTER_PICKUP_BOTTOM = 0;
constexpr int ARM_MOTOR = 0;
constexpr int LEFT_GANTRY_MOTOR = 0;
constexpr int RIGHT_GANTRY_MOTOR = 0;
constexpr int PINCHER_SERVO = 0;
//DIO
constexpr int GANTRY_ENCODER_CHANNELA = 0;
constexpr int GANTRY_ENCODER_CHANNELB = 0;

constexpr int SHOOTER_ENCODER_CHANNELA = 0;
constexpr int SHOOTER_ENCODER_CHANNELB = 0;

constexpr int ARM_ENCODER_CHANNELA = 0;
constexpr int ARM_ENCODER_CHANNELB = 0;

constexpr int LEFT_ENCODER_CHANNEL_A = 9;
constexpr int LEFT_ENCODER_CHANNEL_B = 8;

constexpr int RIGHT_ENCODER_CHANNEL_A = 9;
constexpr int RIGHT_ENCODER_CHANNEL_B = 8;

constexpr int UPPER_LIMIT = 1;
constexpr int LOWER_LIMIT = 2;

//USB
constexpr int XBOXCONTROLLER_USB = 0;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
