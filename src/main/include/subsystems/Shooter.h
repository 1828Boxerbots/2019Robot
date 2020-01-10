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
#include <frc/DigitalInput.h>

using namespace frc;

class Shooter : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
Spark m_shooterPickupTop{SHOOTER_PICKUP_TOP};
Spark m_shooterPickupBottom{SHOOTER_PICKUP_BOTTOM};

DigitalInput m_shooterStop{SHOOTER_STOP};

Spark m_shooterMotor {SHOOTER_WINDOW_MOTOR};
AnalogTrigger m_shooterEncoder {SHOOTER_ENCODER};
Counter* m_counter;

int m_frame = 0;
int m_previousCounterPosition= 0;

float m_speedPrevious;
int m_Position;

Util m_util;
int m_joystickpress = 0;

//moter speed for the pickup 
 public:
  Shooter();
  void InvertMotorsPickUp();
  void InitDefaultCommand() override;
  void TeleopPickUp(XboxController* controller);
  int SetAngle(XboxController* controller);
  void StopMotors();
	int GetPosition();
  void Intialize();

};
