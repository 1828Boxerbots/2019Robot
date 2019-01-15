/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/Util.h"

double Util::Limit(double upperlimit,double lowerlimit,double value)
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

