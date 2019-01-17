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

class Shooter : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
Spark m_shooterPickupTop{SHOOTER_PICKUP_TOP};
Spark m_shooterPickupBottom{SHOOTER_PICKUP_BOTTOM};
Spark m_shooterSeat{SHOOTER_WINDOW_MOTOR};
Encoder *m_pSeatEncoder = new Encoder(SHOOTER_WINDOW_ENCODER_CHANNELA, SHOOTER_WINDOW_ENCODER_CHANNELB, false, Encoder::EncodingType::k4X);
double m_encoderResoultion;
//moter speed for the pickup 
double m_motorSpeedPickup = 0.25;
 public:
  Shooter();
  void InvertMotorsPickUp();
  void SetPickUpMotor(double Speed);
  void InitDefaultCommand() override;
  void TeleopPickUp(XboxController* controller);
  void SetAngle(double angle);


  //finsh the encoder before uses
  void TeleopAim(XboxController* controller);

};
