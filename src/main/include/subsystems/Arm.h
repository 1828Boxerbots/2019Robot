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
#include <frc/XboxController.h>
#include "Util.h"
#include "RobotMap.h"

using namespace frc;
class Arm : public frc::Subsystem 
{
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  Spark m_armMotor {ARM_MOTOR};

  Encoder *m_pArmEncoder = new Encoder(ARM_ENCODER_CHANNELA, ARM_ENCODER_CHANNELB, false, Encoder::EncodingType::k4X);


  Util m_util;
  int m_joystickpress = 0;

 public:
  Arm();
  void InitDefaultCommand() override;
  void InvertMotors();

 //moves the arm to either 90 degrees or 0 degrees
  void ArmUp();
  void ArmDown();

  /*Makes it so that the player can move the arm up/down
  @parn "pcontroller" enters in the address of the controller object to get input*/
  void TeleopArm(XboxController *pController);
};