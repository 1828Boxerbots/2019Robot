/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/Util.h"
Util::Util()
{
}
double Util::Limit(double upperlimit, double lowerlimit, double value)
{
    if (value > upperlimit)
    {
        return upperlimit;
    }
    if (value < lowerlimit)
    {
        return lowerlimit;
    }
    return value;
}
double Util::ToggleSwitch(bool firstbutton, bool secondbuttton, 
    double firstState, double secondState, bool thirdState, int*pJoystickPress)
{
    if ((firstbutton == true) && (*pJoystickPress == 0))
    {
        *pJoystickPress ++;
        return firstState;
    }
    if ((firstbutton == true) && (*pJoystickPress == 1))
    {
        *pJoystickPress --;
        return secondState;
    }
    if (thirdState == true)
    {
        if (secondbuttton == true)
        {
            return 0.0;
        }
    }
    else
    {
    }
    
}


