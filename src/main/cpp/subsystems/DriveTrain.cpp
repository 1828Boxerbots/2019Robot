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
  double LeftDistance = m_pLeftMotorEncoder->GetDistance();
  SmartDashboard::PutNumber("m_pLeftMotorEncoder", (LeftDistance/25.4));

  double RightDistance = m_pRightMotorEncoder->GetDistance();
  SmartDashboard::PutNumber("m_pRightMotorEncoder", (RightDistance/25.4));

  double leftX = controller->GetX(frc::GenericHID::kLeftHand);
  double leftY = controller->GetY(frc::GenericHID::kLeftHand);

  double rightoverallValue = leftX + leftY;
  double leftoverallValue = -leftX + leftY;

  double limitedRightOverallValue = util.Limit(1, -1, rightoverallValue);
  double limitedLeftOverallValue = util.Limit(1, -1, leftoverallValue);

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

void DriveTrain::MoveMotersFwd(double speed, double distanceIninchs)
{
  m_pLeftMotorEncoder->SetDistancePerPulse(1.0);
  m_pRightMotorEncoder->SetDistancePerPulse(1.0);

  m_rightMotor.Set(speed);
  m_leftMotor.Set(speed);

  bool isLeftWheelAtDistance = (m_pLeftMotorEncoder->GetDistance()/25.4) < distanceIninchs;
  bool isRightWheelAtDistance = (m_pRightMotorEncoder->GetDistance()/25.4) < distanceIninchs;
  while((isLeftWheelAtDistance) && (isRightWheelAtDistance)) 
  {
    isLeftWheelAtDistance = (m_pLeftMotorEncoder->GetDistance()/25.4) < distanceIninchs;
    isRightWheelAtDistance = (m_pRightMotorEncoder->GetDistance()/25.4) < distanceIninchs;
  }
  StopDriveMotors();
}

void DriveTrain::MoveMotersTurn(double angle, double speed)
{
  //Change rate during debuging 
  double rate = 1;
  double Time = angle/rate;

  m_leftMotor.Set(speed);
  m_rightMotor.Set(-speed);

  Wait(Time);

  StopDriveMotors();
}