/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Arm.h"
#include <frc/SmartDashboard/SmartDashboard.h>

Arm::Arm() : Subsystem("Arm") {}

void Arm::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

}
void Arm::Intialize()
{
	m_armEncoder.SetLimitsVoltage(3.2, 3.4);
	m_counter = new Counter(m_armEncoder);
	m_Position = 0;
  m_previousCounterPosition = m_counter->Get();
}
void Arm::InvertMotors()
{
  m_arm.SetInverted(false);
}
int Arm::GetPosition()
{
  double currentDirection = -m_arm.Get(); 
  SmartDashboard::PutNumber("Current Direction", currentDirection);

  bool triggerState = m_armEncoder.GetTriggerState();
  SmartDashboard::PutBoolean("Trigger State", triggerState);

  double counter = m_counter->Get();
  SmartDashboard::PutNumber("Counter", counter);

  SmartDashboard::PutNumber("Position", m_Position);
	// position from previous direction change plus what's been accumulated so far in this direction
	if (currentDirection > 0.05)
  {
	  m_Position = m_Position + (m_counter->Get() - m_previousCounterPosition); // been going forward so add counter
  }
  if (currentDirection < -0.05)
  {
	  m_Position = m_Position - (m_counter->Get() - m_previousCounterPosition); // been going backward so subtract counter
  }
  m_previousCounterPosition = m_counter->Get();
  return m_Position;
}
void Arm::TeleopArm (XboxController *pController)
{
  int armTick = m_Position;

  double bButton = pController->GetBButton();

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
void Arm::ArmUp()
{
  int armTick = m_Position;
  const double zeroDegree = 0.0;
  if (armTick > zeroDegree)
  {
    m_arm.Set(0.7);
  }
  else
  {
    m_arm.Set(.07);
  }
}
void Arm::ArmDown()
{
  int armTick = m_Position;
  const double ninetyDegree = 43.0;
  if (armTick < ninetyDegree)
  {
    m_arm.Set(-0.7);
  }
  else
  {
    m_arm.Set(0);
  }
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
