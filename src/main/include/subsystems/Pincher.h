/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Servo.h>
#include "RobotMap.h"
#include <frc/XboxController.h>
#include "Util.h"

using namespace frc;
class Pincher : public frc::Subsystem 
{
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
Util m_util;
Servo m_servoPincher {PINCHER_SERVO};
int m_joystickpress = 0;
 public:
  Pincher();
  void InitDefaultCommand() override;
  void TeleOpPincher(XboxController* pController);
  void AutoOpen();
  void AutoClose();
};
