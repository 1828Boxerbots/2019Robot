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
    bool topLimit = m_topLimit.Get();
    bool lowerLimit = m_lowerLimit.Get();
    if(((topLimit == false) && (lowerLimit == false)) || ((topLimit == false) || (lowerLimit == true)))
    {
        //When the right bumper is pressed, move gantry up
        m_gantryMotorLeft.Set(0.5);
        m_gantryMotorRight.Set(0.5);
    }
}
void Gantry::MoveDown()
{
    bool lowerLimit = m_lowerLimit.Get();
    bool upperLimit = m_upperLimit.Get();
     if(((topLimit == false) && (lowerLimit == false)) ||((topLimit == true) && (lowerLimit == false )))
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
    double distance = ((m_gantryEncoder.GetRaw()) / 25.4)
    while((topLimit == false) && (lowerLimit == true))
    {
        
    }
}

void Gantry::MoveToLevelOne(double distanceIninchs)
{
    double distance = ((m_pGantryEncoder.GetRaw()) / 25.4);

    MoveUp();

    while(distanceTicknumber > distance)
    {
        if ((upperLimit == true) || (lowerLimit == true))
        {
            StopMotors();
        }
         Wait(0.2);
    }

    StopMotors();

}