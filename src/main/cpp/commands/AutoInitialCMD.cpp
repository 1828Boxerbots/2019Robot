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