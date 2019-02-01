/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoCMD.h"
#include "Robot.h"

void AutoCMD::AutoInitialCMD()
{
    // move fork fowards
    Robot::m_arm->ArmUp();

    //Lift gantry
    Robot::m_gantry->MoveToStandardLevel();

    //Move fork backwards
    Robot::m_arm->ArmDown();

    //Open Peg
    Robot::m_pincher->AutoOpen();

    //move gantry to first level
    Robot::m_gantry->MoveToLevelOne();
}