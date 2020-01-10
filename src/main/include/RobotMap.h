/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
//PWM
constexpr int LEFTMOTOR = 2;
constexpr int RIGHTMOTOR = 6;
constexpr int SHOOTER_WINDOW_MOTOR = 0;
constexpr int SHOOTER_PICKUP_TOP = 5;
constexpr int SHOOTER_PICKUP_BOTTOM = 1;
constexpr int ARM_MOTOR = 9;
constexpr int GANTRY_MOTOR = 7;
constexpr int PINCHER_SERVO = 3;

//DIO

constexpr int RIGHT_ENCODER_CHANNEL_A = 2;
constexpr int RIGHT_ENCODER_CHANNEL_B = 3;

constexpr int LEFT_ENCODER_CHANNEL_A = 1;
constexpr int LEFT_ENCODER_CHANNEL_B = 0;


constexpr int GANTRY_ENCODER_CHANNEL_A = 7;
constexpr int GANTRY_ENCODER_CHANNEL_B = 8;

constexpr int BOTTOM_LIMIT = 9;
constexpr int TOP_LIMIT = 7;

constexpr int SHOOTER_STOP = 6;

//USB
constexpr int XBOXCONTROLLER_USB = 0;

//Analog
constexpr int SHOOTER_ENCODER = 3;

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
