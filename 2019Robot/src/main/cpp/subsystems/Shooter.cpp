/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem") {}

void Shooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Shooter::TeleopDrive(XboxController* controller)
{
  double GetRightTrigger = controller->GetTriggerAxis(GenericHID::kRightHand);
  double GetLeftTrigger = controller->GetTriggerAxis(GenericHID::kLeftHand);

  if (GetLeftTrigger >= 0.1)
  {
    m_shooterPickupTop.Set(-0.5);
  }
  if (GetLeftTrigger >= 0.1)
  {
    m_shooterPickupTop.Set(-0.5);
  }

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
