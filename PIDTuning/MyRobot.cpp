#include "WPILib.h"
#include "Schematic.h"
#include "Thing.h"
#include "CompressorManager.h"
class RobotDemo : public SimpleRobot
{
	Joystick Controller;
	Thing SpdSet;
	CompressorManager compress;
private:

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
			compress.checkCompressor();
			SpdSet.Setspeed(Controller.GetRawAxis(2), Controller.GetRawAxis(4), Controller.GetRawButton(1), Controller.GetRawButton(2), Controller.GetRawButton(6));
		}
	}
	
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);
