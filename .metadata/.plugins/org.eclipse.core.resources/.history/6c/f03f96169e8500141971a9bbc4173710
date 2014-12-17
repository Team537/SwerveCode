#include "Thing.h"
#include "Schematic.h"
#include "WPILib.h"

void Thing::Setspeed(float axis, int bshift, int buttonswitch)
{
	LEnc.Start();
	if (fabs(axis) >= .1){
	LDVictor.Set(axis);
	}
	
	cencrate = LEnc.GetRate();
	if (cencrate >= encmax)
	{
		encmax = cencrate;
	}
	LSpd.SetPID(.05,0,0,.2);
	if (buttonswitch = 1)
	{
		LSpd.SetSetpoint(.5*MAX_RATE);
	}
	else
		LSpd.SetSetpoint(.75*MAX_RATE);
	SmartDashboard::PutNumber("LSpd Input", LEnc.GetRate());
	SmartDashboard::PutNumber("Setpoint", LSpd.GetSetpoint());
	SmartDashboard::PutNumber("Max Left Rate", encmax);
	SmartDashboard::PutNumber("LeftRate2", cencrate);
	SmartDashboard::PutNumber("LSpd Error", LSpd.GetError());
	SmartDashboard::PutNumber("LSpd output",LDVictor.Get());

}
