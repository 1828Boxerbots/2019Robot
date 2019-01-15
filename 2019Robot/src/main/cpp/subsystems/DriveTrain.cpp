/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "Util.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace frc;
DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::TeleopDrive(XboxController* controller)
{
  double LeftDistance = m_leftMotorEncoder->GetDistance();
  SmartDashboard::PutNumber("m_leftMotorEncoder", (LeftDistance/25.4));

  double RightDistance = m_rightMotorEncoder->GetDistance();
  SmartDashboard::PutNumber("m_rightMotorEncoder", (RightDistance/25.4));

  double leftX = controller->GetX(frc::GenericHID::kLeftHand);
  double leftY = controller->GetY(frc::GenericHID::kLeftHand);

  double rightoverallValue = leftX + leftY;
  double leftoverallValue = -leftX + leftY;

  double limitedRightOverallValue = Util::Limit(1, -1, rightoverallValue);
  double limitedLeftOverallValue = Util::Limit(1, -1, leftoverallValue);

  m_leftMotor.Set(limitedLeftOverallValue);
  m_rightMotor.Set(limitedRightOverallValue);
}

void DriveTrain::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::StopDriveMotors()
{
  m_leftMotor.Set(0.0);
  m_rightMotor.Set(0.0);
}
void DriveTrain::InvertMotors()
{
  m_leftMotor.SetInverted(true);
  m_rightMotor.SetInverted(false);
}