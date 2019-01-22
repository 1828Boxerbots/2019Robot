/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

using namespace frc;
Shooter::Shooter() : Subsystem("Shooter")
{
  m_pShooterEncoder->Reset();
}

void Shooter::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void Shooter::SetAngle(XboxController* controller)
{
  double shooterTick = m_pShooterEncoder->GetRaw();
  bool Xbutton = controller->GetXButton();
  bool Abutton = controller->GetAButton();
  int joystickpress = 0;
  const double ANGLE_45 = 21.0;
  const double ANGLE_90 = 43.0;

  double position = m_util.ToggleSwitch(Xbutton, Abutton, ANGLE_45, ANGLE_90, true, &joystickpress);

  if (shooterTick < position)
  {
    m_shooterAim.Set(0.75);
  }
  else
  {
    m_shooterAim.Set(-0.75);
  }
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
// Put methods for controlling this subsystem
// here. Call these from Commands.
