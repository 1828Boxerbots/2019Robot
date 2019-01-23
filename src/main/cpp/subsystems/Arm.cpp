/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Arm.h"

Arm::Arm() : Subsystem("Arm") {}

void Arm::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void InvertMotors ()
{
  m_arm.SetInverted(false);
}

void Arm::TeleopArm (XboxController *pController)
{
  double armTick = m_pArmEncoder->GetRaw();

  double bButton = controller->GetBButton();

  const double ANGLE_0 = 0.0;
  const double ANGLE_90 = 43.0;

  double position = m_util.ToggleSwitch(bButton, false, ANGLE_0, ANGLE_90, false, &m_joystickpress);

  if (armTick < position)
  {
    m_arm.Set(0.75);
  }
  else
  {
    m_arm.Set(-0.75);
  }
  // stop the motor if it is in the range
  if ((armTick < position-1.0) || (armTick > position+1.0))
  {
    m_arm.Set(0);
  }
}
// Put methods for controlling this subsystem
// here. Call these from Commands.