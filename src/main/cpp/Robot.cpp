/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <cameraserver/CameraServer.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

std::shared_ptr <DriveTrain> Robot::m_driveTrain = std::make_shared<DriveTrain>();
std::shared_ptr <Shooter> Robot::m_shooter = std::make_shared<Shooter>();
std::shared_ptr <Arm> Robot::m_arm = std::make_shared<Arm>();
std::shared_ptr <Pincher> Robot::m_pincher = std::make_shared<Pincher>();
std::shared_ptr <Gantry> Robot::m_gantry = std::make_shared<Gantry>();
OI Robot::m_oi;

class AutoOneCMD : public AutoCMD
{
  public:
    AutoOneCMD() { }
    void Execute() override
    {
      m_count++;
      SmartDashboard::PutString("Position", "AutoOneCMD");
      SmartDashboard::PutNumber("Position Count", m_count);
//      AutoOne();
    }
};
class AutoTwoCMD : public AutoCMD
{
  public:
    AutoTwoCMD() { }
    void Execute() override
    {
      m_count++;
      SmartDashboard::PutString("Position", "AutoTwoCMD");
      SmartDashboard::PutNumber("Position Count", m_count);
//      AutoTwo();
    }
};
class AutoThreeCMD : public AutoCMD
{
  public:
    AutoThreeCMD() { }
    void Execute() override
    {
      m_count++;
      SmartDashboard::PutString("Position", "AutoThreeCMD");
      SmartDashboard::PutNumber("Position Count", m_count);
//      AutoThree();
    }
};

void Robot::RobotInit() 
{  
  Robot::m_driveTrain->CalibrateGyro();

  m_autoMode = Shuffleboard::GetTab("Auto")
    .Add("Robot Position", 1)
    .WithWidget("Combo Box Chooser")
    .GetEntry();
  m_int = (int)m_autoMode.GetDouble(0);

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{
  
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() 
{
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }
  m_autoCMD.Start();
  /*
  bool autoMode = SmartDashboard::GetBoolean("Auto Mode", false);

  if (autoMode == false)
  {
    //Starts TeleOp Auto
    m_driveTrainCMD.Start();
    m_shooterCMD.Start();
    m_armCMD.Start();
    m_pincherCMD.Start();
    m_gantryCMD.Start();
  }
  else
  {
    /*Auto.reset(autoChooser.GetSelected());
    if (Auto.get() != nullptr)
    {
      Auto->Start();
    }
  }*/
}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit() 
{
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.ks
  m_driveTrainCMD.Start();
  m_shooterCMD.Start();
  m_armCMD.Start();
  m_pincherCMD.Start();
  m_gantryCMD.Start();
}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif