/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

class Util
{
public:
  Util();
  ~Util();

  double Limit(double upperlimit, double lowerlimit, double value);
  double ToggleSwitch(bool firstbutton, bool secondbuttton, double firstState, double secondState, bool thirdState, int*pJoystickPress);

private:

};