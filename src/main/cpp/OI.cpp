/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

//#include <frc/WPILib.h>

XboxController* OI::GetController()
{
  return &controller;
}
XboxController* OI::GetController2()
{
  return &controller2;
}
XboxController* OI::GetController3()
{
  return &controller3;
}
OI::OI()
{
  // Process operator interface input here.
}
