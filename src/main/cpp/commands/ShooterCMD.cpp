/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShooterCMD.h"
#include "Robot.h"

ShooterCMD::ShooterCMD() 
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_shooter.get());
}

// Called just before this Command runs the first time
void ShooterCMD::Initialize() 
{
  Robot::m_shooter->InvertMotorsPickUp();
  Robot::m_shooter->Intialize();
}

// Called repeatedly when this Command is scheduled to run
void ShooterCMD::Execute() 
{
  Robot::m_shooter->TeleopPickUp(Robot::m_oi.GetController());
  Robot::m_shooter->SetAngle(Robot::m_oi.GetController());
  Robot::m_shooter->GetPosition();

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void ShooterCMD::End() 
{
  Robot::m_shooter->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterCMD::Interrupted() {}
