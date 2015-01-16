#ifndef THING_H
#define THING_H
#include "Schematic.h"
#include "cmath"
#include "WPILib.h"

class Thing
{
	
	Victor LDVictor, RDVictor;
	Encoder LEnc, REnc; 
	float deadband;
	PIDController LSpd, RSpd;
	Timer inittimer;
	Solenoid dshift;
	
public:
	//void SetVariables(float Magnitude, float DirectionRadians, float Twist);
	Thing(void):
		LDVictor(L_VICTOR),
		RDVictor(R_VICTOR),
		LEnc(LENC,true,CounterBase::k4X),
		REnc(RENC,true,CounterBase::k4X),
		LSpd( LP,0, 0, &LEnc, &LDVictor),
		RSpd(RP,0, 0, &REnc, &RDVictor),
		dshift(1,1)
	{
		deadband = .1;
		//PID
		LSpd.SetAbsoluteTolerance(3);
		LSpd.SetOutputRange(-1,1);
		LEnc.SetDistancePerPulse(0.05026548);
		LEnc.SetPIDSourceParameter(PIDSource::kRate);
		RSpd.SetAbsoluteTolerance(3);
		RSpd.SetOutputRange(-1,1);
		REnc.SetDistancePerPulse(0.05026548);
		REnc.SetPIDSourceParameter(PIDSource::kRate);
		//Other Sets
		//Potfeedbackmax = 850;
		//Potfeedbackmin = 50;
		Lencmax = 0;
		Rencmax = 0;
		firsttime =true;
	}
	void Setspeed(float Laxis, float Raxis, int bshifth, int bshiftl, int buttonswitch);

private:
	double cLencrate, cRencrate;
	double Lencmax, Rencmax;
	bool firsttime;
};

#endif
