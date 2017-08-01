#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Lib830.h>
#include "input/GamepadF310.h"

using namespace Lib830;

class Robot: public frc::IterativeRobot {
public:
	static const int LEFT_PWM_ONE = 0; //placeholder
	static const int LEFT_PWM_TWO = 0; //placeholder
	static const int RIGHT_PWM_ONE = 0; //placeholder
	static const int RIGHT_PWM_TWO = 0; //placeholder

	RobotDrive * drive;

	GamepadF310 * pilot;
	GamepadF310 * copilot;

	static const int TICKS_TO_ACCEL = 15;
	float previousSpeed = 0;

	void RobotInit() {
		drive = new RobotDrive(
					new VictorSP(LEFT_PWM_ONE),
					new VictorSP(LEFT_PWM_TWO),
					new VictorSP(RIGHT_PWM_ONE),
					new VictorSP(RIGHT_PWM_TWO)
		);

		pilot = new GamepadF310(0);
		copilot = new GamepadF310(1);

		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	void AutonomousInit() override {
		autoSelected = chooser.GetSelected();
		// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if (autoSelected == autoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (autoSelected == autoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {

		float targetSpeed = pilot->LeftY();

		if (fabs(targetSpeed) < 0.13) {
			targetSpeed = 0;
		}

		float speed = accel(targetSpeed, previousSpeed, TICKS_TO_ACCEL);
		previousSpeed = speed;

		float turn = pilot->RightX();
		drive->ArcadeDrive(speed,turn);
	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
};

START_ROBOT_CLASS(Robot)
