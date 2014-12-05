#include "WPILib.h"
#include "Schematic.h"
#include "CompressorManager.h"
#include "Swerve.h"

class RobotDemo : public SimpleRobot
{
private:
	Joystick Controller;
	CompressorManager Comp;
	Swerve Sdrive;
public:
	RobotDemo(void):
		Controller(CONTROLLER)
	{
	
	}

	void Autonomous()
	{
		
	}

	void OperatorControl()
	{
		while (IsOperatorControl())
		{
			//Comp.checkCompressor();
			SmartDashboard::PutNumber("Controller Angle", (Controller.GetDirectionRadians()*(180/PI)));
			Sdrive.SetVariables( Controller.GetMagnitude(),  Controller.GetDirectionRadians(),  Controller.GetRawAxis(ZAXIS));
			Sdrive.FindWheelSpeed();
			Sdrive.Sort();
			Sdrive.Ramping();
			//Sdrive.SetWheelSpeed();
			Sdrive.FindAngle();
			Sdrive.SetAngle();
		}
	}
	
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

