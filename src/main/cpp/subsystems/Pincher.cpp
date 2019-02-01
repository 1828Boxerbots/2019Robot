/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Pincher.h"

Pincher::Pincher() : Subsystem("Pincher") {}

void Pincher::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Pincher::TeleOpPincher(XboxController* pController)
{
  bool yButton = pController->GetYButton();

  double ninetyDegrees = 90;
  double zeroDegrees = 0;

  double angle = m_util.ToggleSwitch(yButton, false, ninetyDegrees, zeroDegrees, false, &m_joystickpress);

  m_servoPincher.SetAngle(angle);
}

void Pincher::AutoOpen()
{
  double angle = 90;
  m_servoPincher.SetAngle(angle);
}

void Pincher::AutoClose()
{
  double angle = 0;
  m_servoPincher.SetAngle(angle);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
