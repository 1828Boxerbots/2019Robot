/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GantryCMD.h"
#include "Robot.h"
#include "OI.h"

GantryCMD::GantryCMD() 
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_gantry.get());
}

// Called just before this Command runs the first time
void GantryCMD::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void GantryCMD::Execute() 
{
  Robot::m_gantry->TeleopGantry(Robot::m_oi.GetController());
}

// Make this return true when this Command no longer needs to run execute()
bool GantryCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void GantryCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GantryCMD::Interrupted() {}