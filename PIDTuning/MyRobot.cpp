#include "WPILib.h"
#include "Schematic.h"
#include "Thing.h"
#include "CompressorManager.h"
#include "SwerveModule.h"
#include "PIDValue.h"
#include <ctime>
class RobotDemo : public SimpleRobot
{
	
	//Thing SpdSet;
	//CompressorManager compress;
	
private:
	SwerveModule *FrontLeftMod, *FrontRightMod, *BackLeftMod, *BackRightMod;
	Joystick *Controller;
	float AngleSetpoint, PChangeTest, p, i, d;
	
	Timer newtime;
	float oldtime;
public:
	RobotDemo()
	
	{
		Controller = new Joystick(CONTROLLER);
		PIDValue *FrontLeftAngleValues = new PIDValue(.004,0,.003, 40, 925, -.5,.5);
		PIDValue *FrontRightAngleValues = new PIDValue(.004,0.002,0.008, 36, 937, -.5, .5);
		PIDValue *BackLeftAngleValues = new PIDValue(.008,0.002,0.016,36,925,-.5,.5);
		PIDValue *BackRightAngleValues = new PIDValue(-.008,-0.002,-.016,36,925,-.5,.5);
		FrontLeftMod = new SwerveModule(1,2,5,6,4, FrontLeftAngleValues, "FrontLeft",0);
		FrontRightMod = new SwerveModule(8,6,1,2,3,FrontRightAngleValues,"FrontRight",587);
		BackLeftMod = new SwerveModule(4,5,7,8,5,BackLeftAngleValues, "BackLeft",0);
		BackRightMod = new SwerveModule(7,3,3,4,6,BackRightAngleValues, "BackRight",322);
		p = .004;
		i = 0;
		d = 0;
	} 
	void Autonomous()
	{
		
	}
	
	void OperatorControl()
	{
		FrontLeftMod->Initialize();
		FrontRightMod->Initialize();
		BackLeftMod->Initialize();
		BackRightMod->Initialize();
		newtime.Start();
		while (IsOperatorControl())
		{
			//testing.Set(0.25);
			//compress.checkCompressor();
			//SpdSet.Setspeed(Controller.GetRawAxis(2), Controller.GetRawAxis(4), Controller.GetRawButton(1), Controller.GetRawButton(2), Controller.GetRawButton(6));
			//FrontLeftMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			//FrontRightMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			//BackLeftMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			//BackRightMod->drive(Controller->GetMagnitude(),Controller->GetDirectionDegrees ());
			if (Controller->GetRawButton(1) == 1){
				AngleSetpoint = 150;
			}
			else {
				AngleSetpoint = 500;
			}
			//FrontLeftMod->AutoDrive(AngleSetpoint);
			FrontRightMod->AutoDrive(AngleSetpoint);
			//BackLeftMod->AutoDrive(AngleSetpoint);
			BackRightMod->AutoDrive(AngleSetpoint);
			
 	/*	if(newtime.Get() >= .25)
			{
				if (Controller->GetRawButton(7)==1)
				{
					p-=.001;
				}
				if (Controller->GetRawButton(8)==1)  
				{
					p+=.001;
				}
				if (Controller->GetRawButton(9)==1)
				{
					i-=.001;
				}
				if (Controller->GetRawButton(10)==1)  
				{
					i+=.001;
				}
				if (Controller->GetRawButton(11)==1)
				{
					d-=.001;
				}
				if (Controller->GetRawButton(12)==1)  
				{
					d+=.001;
				}
			SmartDashboard::PutNumber("P Change Test", PChangeTest);
				newtime.Stop();
				newtime.Reset();
				newtime.Start();
				FrontRightMod->PIDAdjust(p,i,d);			
				}*/
		}
	}
	
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);
