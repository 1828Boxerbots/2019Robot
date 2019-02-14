/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoCMD.h"
#include "Robot.h"
void AutoCMD::AutoOne()
{
    if (m_isRunning == true)
    {
        return;
    }
    m_isRunning = true;
    Robot::m_driveTrain->InvertMotors();
    //AutoInitialCMD();

    //Drive Forward in inches
    //Robot::m_driveTrain->DriveForward(10);  
    
    //Turn left in degrees
    //Robot::m_driveTrain->TurnRight(90);
    /*
    Robot::m_driveTrain->DriveForward(40);

    Robot::m_driveTrain->TurnRight(63);

    Robot::m_driveTrain->DriveForward(30);

    Robot::m_driveTrain->DriveForward(5);

    Robot::m_pincher->AutoClose();

    Robot::m_driveTrain->DriveBackward(10);
    */
   //Robot::m_driveTrain->StopDriveMotors();
    m_isRunning = false;
}