/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Gantry.h"
#include "Util.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace frc;
Gantry::Gantry() : Subsystem("Gantry") {}
void Gantry::InvertMotors()
{
  m_gantryMotorLeft.SetInverted(true);
  m_gantryMotorRight.SetInverted(false);
}

void Gantry::Teleop(XboxController* pController)
{
    //Hooks up the bumper variables to the actual bumpers on the controller
    bool rightBumper = pController->GetBumper(GenericHID::kRightHand);
    bool leftBumper = pController->GetBumper(GenericHID::kLeftHand);
    if(rightBumper == true && leftBumper == false)
    {
       MoveUp();
    }
    else
    {
        if(leftBumper == true && rightBumper == false)
        {
            MoveDown();
        }
        else
        {
            StopMotors();
        }
    }
}

void Gantry::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Gantry::MoveUp()
{
    bool UpperLimit = m_topLimit.Get();

    if(UpperLimit == false)
    {
        //When the right bumper is pressed, move gantry up
        m_gantryMotorLeft.Set(0.5);
        m_gantryMotorRight.Set(0.5);
    }
}
void Gantry::MoveDown()
{
    bool lowerLimit = m_lowerLimit.Get();
    
     if(lowerLimit == false)
     {
        //When the left bumper is pressed, move gantry down
        m_gantryMotorLeft.Set(-0.5);
        m_gantryMotorRight.Set(-0.5);
     }
}
void Gantry::StopMotors()
{
    //stop both motors
    m_gantryMotorLeft.Set(0.0);
    m_gantryMotorRight.Set(0.0);
}

void Gantry::MoveToStandardLevel()
{
    double distance = ((m_pGantryEncoder->GetRaw()) / MM_TO_IN);
    while (m_lowerLimit.Get() == false)
    {
        MoveDown();
    }
    StopMotors();
}

void Gantry::MoveToLevelOne(double distanceIninchs)
{
    double distance = ((m_pGantryEncoder->GetRaw()) / MM_TO_IN);

    MoveUp();

    while(distanceIninchs > distance)
    {
        if ((m_topLimit.Get() == true) || (m_lowerLimit.Get() == true))
        {
            StopMotors();
        }
         Wait(0.2);
    }

    StopMotors();

}