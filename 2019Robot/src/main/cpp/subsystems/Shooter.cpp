/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"
#include <cmath>

Shooter::Shooter() : Subsystem("ExampleSubsystem")
{
  m_pSeatEncoder->Reset();
}

void Shooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void Shooter::SetAngle(double angle)
{
  double intal_tick;
  // distance form the tick to
  double differnce = ((angle/m_encoderResoultion) - intal_tick);
  double direction = (differnce/std::abs(differnce));

  m_shooterSeat.Set(0.1 * direction);
  double current_tick = 0.0;
  while (current_tick != differnce))
  {
    current_tick = m_pSeatEncoder->GetRaw();
  }
  m_shooterSeat.Set(0.0);
  intal_tick = current_tick;
}
void Shooter::TeleopPickUp(XboxController* controller)
{
  //Get the trigger as double 1 and double 0
  double GetRightTrigger = controller->GetTriggerAxis(GenericHID::kRightHand);
  double GetLeftTrigger = controller->GetTriggerAxis(GenericHID::kLeftHand);

  //check right trigger, right override left if both are press
  if (GetRightTrigger > 0.1)
  {
    SetPickUpMotor(m_motorSpeedPickup);
  }
  else
  {
    // run only after reading right trigger as false 
    if (GetLeftTrigger > 0.1)
    {
      SetPickUpMotor(m_motorSpeedPickup * -1);
    }
    else 
    {
      //if both trigger are false the it stop the motors 
      SetPickUpMotor(0.0);
    }
  }

}

void Shooter::TeleopAim(XboxController* controller)
{
  double RightYJoyStick = controller->GetY(GenericHID::kRightHand);
  if (RightYJoyStick >= 0.9)
  {
    SetAngle(45);
  }
  if (RightYJoyStick <= -0.9)
  {
    SetAngle(90);
  }
}
void Shooter::SetPickUpMotor(double Speed)
{
  m_shooterPickupTop.Set(Speed);
  m_shooterPickupBottom.Set(Speed);
}
void Shooter::InvertMotorsPickUp()
{
  m_shooterPickupBottom.SetInverted(true);
  m_shooterPickupTop.SetInverted(false);
  m_shooterSeat.SetInverted(false);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
