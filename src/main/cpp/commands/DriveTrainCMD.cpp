/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveTrainCMD.h"
#include "Robot.h"


DriveTrainCMD::DriveTrainCMD() 
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_driveTrain.get());
}
// Called just before this Command runs the first time
void DriveTrainCMD::Initialize() 
{
  Robot::m_driveTrain->StopDriveMotors();
  Robot::m_driveTrain->InvertMotors();
}
// Called repeatedly when this Command is scheduled to run
void DriveTrainCMD::Execute() 
{
Robot::m_driveTrain->TeleopDrive(Robot::m_oi.GetController());
}
// Make this return true when this Command no longer needs to run execute()
bool DriveTrainCMD::IsFinished() 
{ 
  return false; 
}
// Called once after isFinished returns true
void DriveTrainCMD::End() 
{
  Robot::m_driveTrain->StopDriveMotors();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTrainCMD::Interrupted() 
{

}
