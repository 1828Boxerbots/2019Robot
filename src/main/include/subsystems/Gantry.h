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
  // constants
  const double LOWER_LIMIT_ENCODER_VALUE = 50;
  const double UPPER_LIMIT_ENCODER_VALUE = 1003;
  const double STANDARD_LEVEL_ENCODER_VALUE = 123;
  const double LEVEL_ONE_ENCODER_VALUE = 456;
  // hardware used by subsystem
  Spark m_gantryMotorLeft{LEFT_GANTRY_MOTOR};
  Spark m_gantryMotorRight{RIGHT_GANTRY_MOTOR};
  DigitalInput m_topLimit{UPPER_LIMIT};
  DigitalInput m_lowerLimit{LOWER_LIMIT};
  Encoder m_pGantryEncoder(GANTRY_ENCODER_CHANNELA, GANTRY_ENCODER_CHANNELB, false, Encoder::EncodingType::k4x);
  // private methods
  void MoveUp();
  void MoveDown();
  void StopMotors();
  
 public:
  Gantry();
  void InitDefaultCommand() override;
  void Teleop(XboxController* pController);
  void InvertMotors();
  /*The level that is flush with the arm (StandardGantryLevel)
  The level that is flush with the first hole on the rocket ships (GantryLevelOne)
  Only used for autonomious*/
  void MoveToStandardLevel();
  void MoveToLevelOne(double distanceTicknumber);
};