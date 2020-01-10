/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/XboxController.h>
#include "RobotMap.h"
using namespace frc;

class OI 
{
  private:
  XboxController controller {XBOXCONTROLLER_USB};
  XboxController controller2 {XBOXCONTROLLER_USB2};
  XboxController controller3 {XBOXCONTROLLER_USB3};
 public:
  XboxController* GetController();
  XboxController* GetController2();
  XboxController* GetController3();
  OI();
};
