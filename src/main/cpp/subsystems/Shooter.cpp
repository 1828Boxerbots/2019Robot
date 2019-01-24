/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

using namespace frc;
Shooter::Shooter() : Subsystem("Shooter") {}

void Shooter::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void Shooter::SetAngle(XboxController* controller)
{
  //"shooterTick" get the current tick number of the encoder
  double shooterTick = m_pShooterEncoder->GetRaw();

  //get button state (true or false)
  bool xButton = controller->GetXButton();
  bool aButton = controller->GetAButton();

  // this is setting angle to tick numbers
  const double ANGLE_45 = 21.0;
  const double ANGLE_90 = 43.0;

  // set the target tick number to the angle we want
  double position = m_util.ToggleSwitch(xButton, aButton, ANGLE_45, ANGLE_90, true, &m_joystickpress);

  //if the current tick read is less than target then set motor either foward or backwards 
  if (shooterTick < position)
  {
    m_shooterAim.Set(0.75);
  }
  else
  {
    m_shooterAim.Set(-0.75);
  }
  // stop the motor if it is in the range
  if ((shooterTick < position-1.0) || (shooterTick > position+1.0))
  {
    m_shooterAim.Set(0);
  }

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
  m_shooterAim.SetInverted(false);
}
void Shooter::StopMotors()
{
  m_shooterPickupBottom.Set(0);
  m_shooterPickupTop.Set(0);
  m_shooterAim.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
