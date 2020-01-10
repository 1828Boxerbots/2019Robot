/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace frc;
Shooter::Shooter() : Subsystem("Shooter") {}

void Shooter::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void Shooter::Intialize()
{
	m_shooterEncoder.SetLimitsVoltage(3.2, 3.4);
	m_counter = new Counter(m_shooterEncoder);
	m_Position = 0;
  m_previousCounterPosition = m_counter->Get();
}

int Shooter::GetPosition()
{
  double currentDirection = -m_shooterMotor.Get(); 
  SmartDashboard::PutNumber("Current Direction", currentDirection);

  bool triggerState = m_shooterEncoder.GetTriggerState();
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

int Shooter::SetAngle(XboxController* controller)
{
  m_shooterMotor.Set(controller->GetY(GenericHID::kRightHand));
  
  /*
  bool xButton = controller->GetXButton();
  bool aButton = controller->GetAButton();

  const double ANGLE_45 = 22.0;
  const double ANGLE_90 = 49.0;

  double targetPosition = m_util.ToggleSwitch(xButton, true, ANGLE_45, ANGLE_90, aButton, &m_joystickpress);
  SmartDashboard::PutNumber("TargetPosition", targetPosition);
  SmartDashboard::PutNumber("Old Position", m_Position);

  if (m_Position < targetPosition)
  {
    m_shooterMotor.Set(-0.5);
  }
  if (m_Position > targetPosition)
  {
    m_shooterMotor.Set(0.5);
  }
  else
  {
    // stop the motor if it is in the range
    if ((m_Position < targetPosition-1.0) || (m_Position > targetPosition+1.0))
    {
      m_shooterMotor.Set(0);
    }
  }
  return m_Position;
  */
}
void Shooter::TeleopPickUp(XboxController* controller)
{
  //Get the trigger as double 1 and double 0
  double GetRightTrigger = controller->GetTriggerAxis(GenericHID::kRightHand);
  double GetLeftTrigger = controller->GetTriggerAxis(GenericHID::kLeftHand);

  double MotorSpeedPickup = 0.75;
  //check right trigger, right override left if both are press
  if (GetRightTrigger > 0.1)
  {
    m_shooterPickupTop.Set(MotorSpeedPickup);
    m_shooterPickupBottom.Set(MotorSpeedPickup);
  }
  else
  {
    // run only after reading right trigger as false 
    if (GetLeftTrigger > 0.1)
    {
      m_shooterPickupTop.Set(MotorSpeedPickup);
      m_shooterPickupBottom.Set(MotorSpeedPickup);
    }
    else 
    {
      //if both trigger are false the it stop the motors 
      m_shooterPickupTop.Set(0);
      m_shooterPickupBottom.Set(0);
    }
  }

}
void Shooter::InvertMotorsPickUp()
{
  m_shooterPickupBottom.SetInverted(true);
  m_shooterPickupTop.SetInverted(false);
  m_shooterMotor.SetInverted(false);
}
void Shooter::StopMotors()
{
  m_shooterPickupBottom.Set(0);
  m_shooterPickupTop.Set(0);
  m_shooterMotor.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
