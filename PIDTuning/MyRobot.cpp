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
	float AngleSetpoint, PChangeTest, p, i, d, NAngleSetpoint;
	Timer newtime;
	float oldtime;
	int sign;
public:
	RobotDemo()
	
	{
		Controller = new Joystick(CONTROLLER);
		
		PIDValue *FrontLeftAngleValues = new PIDValue(.0034,0.0004,.0003, 40, 925, -.5,.5);
		PIDValue *FrontRightAngleValues = new PIDValue(.0018,0.0001,0.0012, 36, 937, -.5, .5);
		PIDValue *BackLeftAngleValues = new PIDValue(.0036,0.0004,0.0005,36,925,-.5,.5);
		PIDValue *BackRightAngleValues = new PIDValue(-.004,-0.0001,0.0014,36,925,-.5,.5);
		
		FrontLeftMod = new SwerveModule(1,2,5,6,4, FrontLeftAngleValues, "FrontLeft",0);
		FrontRightMod = new SwerveModule(8,6,1,2,7,FrontRightAngleValues,"FrontRight",0);
		BackLeftMod = new SwerveModule(4,5,7,8,5,BackLeftAngleValues, "BackLeft",0);
		BackRightMod = new SwerveModule(7,3,3,4,6,BackRightAngleValues, "BackRight", -10);
		
		p = .004;
		i = 0;
		d = 0;
	} 
	void Autonomous()
	{
		
	}
	
	void OperatorControl()
	{
		newtime.Start();
	
		FrontLeftMod->Initialize();
		FrontRightMod->Initialize();
		BackLeftMod->Initialize();
		BackRightMod->Initialize();
		AngleSetpoint = .5;
		while (IsOperatorControl())
		{
			//testing.Set(0.25);
			//compress.checkCompressor();
			//SpdSet.Setspeed(Controller.GetRawAxis(2), Controller.GetRawAxis(4), Controller.GetRawButton(1), Controller.GetRawButton(2), Controller.GetRawButton(6));
			//FrontLeftMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			//FrontRightMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			//BackRightMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			//BackLeftMod->drive(Controller->GetRawAxis(1),Controller->GetRawAxis(2));
			
		/*	if (Controller->GetRawButton(1) == 1){
				AngleSetpoint = 650;
			}
			else {
				AngleSetpoint = 445;
			}*/
			if (Controller->GetMagnitude() >= .15)
			{
				NAngleSetpoint = Controller->GetDirectionDegrees();
				SmartDashboard::PutNumber("RawDegrees", Controller->GetRawAxis(2));
				
				if (Controller->GetRawAxis(2) < 0)
				{
					NAngleSetpoint += 90;
					sign = 1;
				}
				else if (NAngleSetpoint > 0) 
				{
					sign = -1;
					NAngleSetpoint -= 90;
					
				}
				else
				{
					sign = -1;
					NAngleSetpoint += 270;
				}				
				
				SmartDashboard::PutNumber("NAngleSetpoint", NAngleSetpoint);
				AngleSetpoint = NAngleSetpoint/180;
			}
				SmartDashboard::PutNumber("Magnitude", Controller->GetMagnitude());
				FrontRightMod->AutoDrive(AngleSetpoint);
				BackLeftMod->AutoDrive(AngleSetpoint);
				BackRightMod->AutoDrive(AngleSetpoint);
				FrontLeftMod->AutoDrive(AngleSetpoint);
				if (FrontRightMod->AtAngle() && BackRightMod->AtAngle() && FrontLeftMod->AtAngle() && BackLeftMod->AtAngle())
				{
					FrontLeftMod->drive(Controller->GetRawAxis(1),-1*sign*Controller->GetMagnitude());
					FrontRightMod->drive(Controller->GetRawAxis(1),-1*sign*Controller->GetMagnitude());
					BackRightMod->drive(Controller->GetRawAxis(1),sign* Controller->GetMagnitude());
					BackLeftMod->drive(Controller->GetRawAxis(1), -1*sign*Controller->GetMagnitude());
				} 
				else
				{
					FrontLeftMod->drive(0,0);
					FrontRightMod->drive(0,0);
					BackRightMod->drive(0,0);
					BackLeftMod->drive(0,0);
				}
			
		/*	AngleSetpoint = Controller->GetDirectionDegrees();
			if (AngleSetpoint < 0)
				AngleSetpoint += 360;
			
			NAngleSetpoint = (AngleSetpoint / 360) * 889 + 40;*/
			SmartDashboard::PutNumber("Angle Setpoint", AngleSetpoint);
			SmartDashboard::PutNumber("N Angle Setpoint", NAngleSetpoint);
			//FrontRightMod->AutoDrive((AngleSetpoint / 360) *901 + 36);
			//BackLeftMod->AutoDrive((AngleSetpoint / 360) * 889 + 36);
			//BackRightMod->AutoDrive((AngleSetpoint / 360) * 889 + 36);
			//FrontLeftMod->AutoDrive((AngleSetpoint / 360) * 885 + 40);
			
 	/*	if(newtime.Get() >= .25)
			{
				if (Controller->GetRawButton(7)==1)
				{
					p-=.0001;
				}
				if (Controller->GetRawButton(8)==1)  
				{
					p+=.0001;
				}
				if (Controller->GetRawButton(9)==1)
				{
					i-=.00001;
				}
				if (Controller->GetRawButton(10)==1)  
				{
					i+=.00001;
				}
				if (Controller->GetRawButton(11)==1)
				{
					d-=.0001;
				}
				if (Controller->GetRawButton(12)==1)  
				{
					d+=.0001;
				}
			SmartDashboard::PutNumber("P Change Test", PChangeTest);
				newtime.Stop();
				newtime.Reset();
				newtime.Start();
				//FrontLeftMod->PIDAdjust(p,i,d);			
				}*/
		}
	}
	
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);
