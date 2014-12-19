#include "Thing.h"
#include "Schematic.h"
#include "WPILib.h"

void Thing::Setspeed(float Laxis, float Raxis, int bshifth, int bshiftl, int buttonswitch)
{
	if (firsttime == true)
	{
		LEnc.Reset();
		REnc.Reset();
		LSpd.Reset();
		RSpd.Reset();
		firsttime = false;
	}
	LEnc.Start();
	REnc.Start();
	/*if (fabs(Laxis) >= .1){
	LDVictor.Set(Laxis);
	}
	if (fabs(Raxis) >= .1){
		RDVictor.Set(Raxis);
	}*/
	if (bshifth == 1)
	{
		dshift.Set(1);
	}
	if (bshiftl== 1)
	{
		dshift.Set(0);
	}
	cLencrate = LEnc.GetRate();
	if (cLencrate >= Lencmax)
	{
		Lencmax = cLencrate;
	}
	cRencrate = REnc.GetRate();
	if (cRencrate >= Rencmax)
	{
		Rencmax = cRencrate;
	}
	LSpd.SetPID(LP,-0.0001,0,(-1/MAX_RATE_LEFT));
	LSpd.Enable();
	RSpd.SetPID(RP,-0.0001,0,(-1/MAX_RATE_RIGHT));
	RSpd.Enable();
	if (buttonswitch == 1)
	{
		LSpd.SetSetpoint(-.5*MAX_RATE_LEFT);
		RSpd.SetSetpoint(-.5*MAX_RATE_RIGHT);
	}
	else
	{
		LSpd.SetSetpoint(.75*MAX_RATE_LEFT);
		RSpd.SetSetpoint(-.75*MAX_RATE_RIGHT);
	}
	
	
	SmartDashboard::PutNumber("LSpd Input", LEnc.GetRate());
	SmartDashboard::PutNumber("L Setpoint", LSpd.GetSetpoint());
	SmartDashboard::PutNumber("Max Left Rate", Lencmax);
	SmartDashboard::PutNumber("LeftRate2", cLencrate);
	SmartDashboard::PutNumber("LSpd Error", LSpd.GetError());
	SmartDashboard::PutNumber("LSpd output",LDVictor.Get());
	SmartDashboard::PutNumber("RSpd Input", REnc.GetRate());
	SmartDashboard::PutNumber("Max Right Rate", Rencmax);
	SmartDashboard::PutNumber("R Setpoint", RSpd.GetSetpoint());
	SmartDashboard::PutNumber("RightRate2", cRencrate);
	SmartDashboard::PutNumber("RSpd Error", RSpd.GetError());

}
