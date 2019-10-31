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

  double rightoverallValue = -leftY - leftX;
  double leftoverallValue = leftX - leftY;

  double limitedRightOverallValue = util.Limit(.75, -.75, rightoverallValue);
  double limitedLeftOverallValue = util.Limit(.75, -.75, leftoverallValue);


  /* There seems to be an issue with Laika moving on her own. These
  if statements are here as a temporary fix to the problem.*/
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
void DriveTrain::DriveForward(double distance)
{
  double wheelRadius = 3;
  m_leftMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  m_rightMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  double leftDistance = (m_leftMotorEncoder.GetDistance() / 25.4);
  double rightDistance = (m_rightMotorEncoder.GetDistance() / 25.4);

  m_leftMotor.Set(0.35);
  m_rightMotor.Set(0.35);
  while ((leftDistance < distance) || (rightDistance < distance))
  {
    leftDistance = (m_leftMotorEncoder.GetDistance() / 25.4);
    rightDistance = (m_leftMotorEncoder.GetDistance() / 25.4);
    SmartDashboard::PutNumber("Auto Drive Left", leftDistance);
    SmartDashboard::PutNumber("Auto Drive Right", rightDistance);
    SmartDashboard::PutNumber("Auto Drive Distane", distance);
  }
  StopDriveMotors();
}
void DriveTrain::DriveBackward(double distance)
{
  double wheelRadius = 3;
  m_leftMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  m_rightMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * wheelRadius);
  double leftDistance = (m_leftMotorEncoder.GetDistance() / 25.4);
  double rightDistance = (m_rightMotorEncoder.GetDistance() / 25.4);

  m_leftMotor.Set(-0.35);
  m_rightMotor.Set(-0.35);
  while ((leftDistance < distance) || (rightDistance < distance))
  {
    leftDistance = (m_leftMotorEncoder.GetDistance() / 25.4);
    rightDistance = (m_leftMotorEncoder.GetDistance() / 25.4);
    SmartDashboard::PutNumber("Auto Drive Left", leftDistance);
    SmartDashboard::PutNumber("Auto Drive Right", rightDistance);
    SmartDashboard::PutNumber("Auto Drive Distane", distance);
  }
  StopDriveMotors();
}
void DriveTrain::TurnRight(double degree)
{
  double angle = 0;
  degree = 45;
  //m_gyro.GetAngle();
  //Set motor to turn right
  //m_leftMotor.Set(0.35);
  //m_rightMotor.Set(-0.35);
  //Wait until it reached the angle
  while(angle < degree)
  {
    double angle2 = m_gyro.GetAngle();
    double turningValue = (kAngleSetpoint - m_gyro.GetAngle()) * kP;
    SmartDashboard::PutNumber("Auto Angle", angle2);
    SmartDashboard::PutNumber("Auto Angle Maybe", turningValue);
    SmartDashboard::PutNumber("Auto Angle Target", degree);
  }
  //Then stop motors
  StopDriveMotors();
}
void DriveTrain::TurnLeft(double degree)
{
  double angle = m_gyro.GetAngle();
  //Set motor to turn left
  m_leftMotor.Set(-0.65);
  m_rightMotor.Set(0.65);
  //Wait until it reached the angle
  while(angle < degree)
  {
    angle = m_gyro.GetAngle();
  }
  //Then stop motors
  StopDriveMotors();
}
void DriveTrain::CalibrateGyro()
{
  m_gyro.Reset();
  m_gyro.Calibrate();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
