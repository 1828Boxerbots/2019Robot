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

  const double MM_TO_IN = 25.4;

    const double m_stdPosition = 104.0;
    const double m_levelOnePosition = 503.0; 


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
    /*The level that is flush with the arm (StandardGantryLevel)
  The level that is flush with the first hole on the rocket ships (GantryLevelOne)
  Only used for autonomious*/
  void MoveToStandardLevel();
  void MoveToLevelOne();
  void MoveToPosition(double distanceTicknumber);
};