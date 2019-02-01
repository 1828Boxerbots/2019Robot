/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace frc;
DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::TeleopDrive(XboxController* controller)
{
  double wheelRadius = 3;
  m_leftMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  double LeftDistance = m_leftMotorEncoder.GetDistance();
  SmartDashboard::PutNumber("m_leftMotorEncoder", (LeftDistance/25.4));

  m_rightMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  double RightDistance = m_rightMotorEncoder.GetDistance();
  SmartDashboard::PutNumber("m_rightMotorEncoder", (RightDistance/25.4));

  double leftX = controller->GetX(frc::GenericHID::kLeftHand);
  double leftY = controller->GetY(frc::GenericHID::kLeftHand);

  double rightoverallValue = -leftX + leftY;
  double leftoverallValue = leftX + leftY;

  double limitedRightOverallValue = util.Limit(.75, -.75, rightoverallValue);
  double limitedLeftOverallValue = util.Limit(.75, -.75, leftoverallValue);

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
  m_leftMotor.SetInverted(false);
  m_rightMotor.SetInverted(true);
}
void DriveTrain::DriveForward(double distance)
{
  double wheelRadius = 3;
  m_leftMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  double LeftDistance = m_leftMotorEncoder.GetDistance();
  if (LeftDistance < distance)
  {
    m_leftMotor.Set(0.65);
    m_rightMotor.Set(0.65);
  }
  else
  {
    StopDriveMotors();
  }
}
void DriveTrain::DriveBackward(double distance)
{
  {
  double wheelRadius = 3;
  m_leftMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  double LeftDistance = m_leftMotorEncoder.GetDistance();
  if (LeftDistance < distance)
  {
    m_leftMotor.Set(-0.65);
    m_rightMotor.Set(-0.65);
  }
  else
  {
    StopDriveMotors();
  }
}
}
void DriveTrain::TurnRight(double degree)
{
  double angle = m_gyro.GetX();
  if (angle < degree)
  {
    m_leftMotor.Set(0.65);
    m_rightMotor.Set(-0.65);
  }
  else
  {
    StopDriveMotors();
  }
}
void DriveTrain::TurnLeft(double degree)
{
  double angle = m_gyro.GetX();
  if (angle < degree)
  {
    m_leftMotor.Set(-0.65);
    m_rightMotor.Set(0.65);
  }
  else
  {
    StopDriveMotors();
  }
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
