/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/Util.h"

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
double Util::ToggleSwitch(bool toggleButton, bool resetButtton, 
    double firstState, double secondState, bool processSecondbutton, int*pJoystickPress)
{
    if ((toggleButton == true) && (*pJoystickPress == 0))
    {
        *pJoystickPress = 1;
        return firstState;
    }
    if ((toggleButton == true) && (*pJoystickPress > 0))
    {
        *pJoystickPress = 0;
        return secondState;
    }
    if (processSecondbutton == true)
    {
        if (resetButtton == true)
        {
            return 0.0;
        }
    }
    if (*pJoystickPress > 0)
    {
        return firstState;
    }
    else
    {
        return secondState;
    }
}


