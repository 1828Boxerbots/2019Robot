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
#include <frc/DigitalInput.h>

using namespace frc;
class Gantry : public frc::Subsystem 
{
 private:
  Spark m_gantryMotor{GANTRY_MOTOR};
  DigitalInput m_topLimit{TOP_LIMIT};
  DigitalInput m_bottomLimit{BOTTOM_LIMIT};

  Encoder m_pGantryEncoder{GANTRY_ENCODER_CHANNEL_A, GANTRY_ENCODER_CHANNEL_B, false, Encoder::EncodingType::k4X};
  void MoveUp();
  void MoveDown();
  void StopMotors();
  
 public:
  Gantry();
  void MoveUntilPosition(double targetposition);
  void InitDefaultCommand() override;
  void TeleopGantry(XboxController* pController);
  void InvertMotors();
};