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
  Util(){}
  ~Util(){}

  double Limit(double upperlimit, double lowerlimit, double value);

  //This function toggles the position with anything that needs to change between angle
  //@parm "firstbutton" = what button you want to use to swtich between the positions
  //        true = when first button is pressed
  //        false = when first button is not pressed
  //@parm "secondbutton" = what button you want to use to go back to the default position for the shooter
  //        true = when second button is pressed
  //        false = when second button is not pressed
  //@parm "firstState" = what position of the encoder you want to start at
  //      this represent number of tick from a encoder
  //@parm "secondState" the second position of the encoder
  //      this represent number of tick from a encoder
  //@parm "processSecondbutton" this is a flag to determine if the second button should be used
  //       only use in shooter.
  //@parm "pJoystickPress" this is a input out parmer and this is use to see what state the motor is at.
  //      Ex.
  //      90 degrees = 1
  //      45 degrees = 0
  double ToggleSwitch(bool toggleButton, bool resetButtton, double firstState, 
    double secondState, bool processSecondbutton, int*pJoystickPress);

private:

};