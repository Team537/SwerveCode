#ifndef THING_H
#define THING_H
#include "Schematic.h"
#include "cmath"
#include "WPILib.h"

class Thing
{
	
	Victor LDVictor;
	Encoder LEnc; 
	float deadband;
	PIDController LSpd;
	Timer inittimer;
	Solenoid dshift;
	
public:
	//void SetVariables(float Magnitude, float DirectionRadians, float Twist);
	Thing(void):
		LDVictor(L_VICTOR),
		LEnc(LENC,true,CounterBase::k4X),
		LSpd( LP,0, 0, &LEnc, &LDVictor),
		dshift(1,1)
	{
		deadband = .1;
		//PID
		LSpd.SetAbsoluteTolerance(.01);
		LSpd.SetOutputRange(-1,1);
		LEnc.SetDistancePerPulse(0.05026548);
		LEnc.SetPIDSourceParameter(PIDSource::kRate);
		//Other Sets
		//Potfeedbackmax = 850;
		//Potfeedbackmin = 50;
		encmax = 0;
	}
	void Setspeed(float axis, int bshift, int buttonswitch);

private:
	double cencrate;
	double encmax;
};

#endif
