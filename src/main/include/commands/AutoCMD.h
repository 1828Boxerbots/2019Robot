/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include <frc/SmartDashboard/SendableChooser.h>

class AutoCMD : public frc::Command 
{
  // member variables
 private:

  static bool m_isRunning;
public:
  static int m_count;

// public functions
public:
  AutoCMD();
  void AutoOne();
  void AutoTwo();
  void AutoThree();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

  

// private functions
  private:
  void AutoInitialCMD();
};