/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Spark.h>
#include <frc/XboxController.h>
#include <frc/Encoder.h>
#include "RobotMap.h"
#include "Util.h"
#include <frc/AnalogInput.h>
#include <frc/AnalogTrigger.h>
#include <frc/Counter.h>

using namespace frc;
class Arm : public frc::Subsystem 
{
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  Spark m_arm {ARM_MOTOR};
  AnalogTrigger m_armEncoder {ARM_ENCODER};
  Counter* m_counter;

  int m_previousCounterPosition = 0;

  int m_Position;

  Util m_util;
  int m_joystickpress = 0;

 public:
  Arm();
  void InitDefaultCommand() override;
  void InvertMotors();
  void TeleopArm(XboxController *pController);
	int GetPosition();
  void Intialize();
  //moves the arm to either 90 degrees or 0 degrees
  void ArmUp();
  void ArmDown();
};