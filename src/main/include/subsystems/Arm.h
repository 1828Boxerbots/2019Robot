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

using namespace frc;
class Arm : public frc::Subsystem 
{
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
Spark m_arm {ARM_MOTOR};
 public:
  Arm();
  void InitDefaultCommand() override;
  void InvertMotors ();
  void TeleopArm ();
};
