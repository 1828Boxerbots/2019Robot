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
class Gantry : public frc::Subsystem 
{
 private:
  Spark m_gantryMotorLeft{LEFT_GANTRY_MOTOR};
  Spark m_gantryMotorRight{RIGHT_GANTRY_MOTOR};

  void MoveUp();
  void MoveDown();
  void StopMotors();
  
 public:
  Gantry();
  void InitDefaultCommand() override;
  void Teleop(XboxController* pController);
  void InvertMotors();
};