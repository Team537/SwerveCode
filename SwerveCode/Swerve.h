#ifndef SWERVE_H
#define SWERVE_H
#include "Schematic.h"
#include "cmath"
#include "WPILib.h"
#include "PotentiometerThreeSixty.h"

class Swerve
{
	
	Victor SFR, SFL, SBR, SBL, AFR, AFL, ABR, ABL;
	Encoder FREnc, FLEnc, BREnc, BLEnc;
	AnalogChannel FRPot, FLPot, BRPot, BLPot; 
	Gyro gyro;
	float A, B, C, D, Ratio, frontrspeed, backrspeed, frontlspeed, backlspeed, FRAng, FLAng, BRAng, BLAng;
	float deadband, deadbandrad;
	PIDController FrontRightAngle, FrontLeftAngle, BackRightAngle, BackLeftAngle, FrontRightSpeed, FrontLeftSpeed, BackRightSpeed, BackLeftSpeed;
	

public:
	void SetVariables(float Magnitude, float DirectionRadians, float Twist);
	Swerve(void):
		SFR(FR_DRIVE_VICTOR),
		SFL(FL_DRIVE_VICTOR),
		SBR(BR_DRIVE_VICTOR),
		SBL(BL_DRIVE_VICTOR),
		AFR(FR_ANGLE_VICTOR),
		AFL(FL_ANGLE_VICTOR),
		ABR(BR_ANGLE_VICTOR),
		ABL(BL_ANGLE_VICTOR),
		FREnc(FR_DRIVE_ENCODER,true,CounterBase::k4X),
		FLEnc(FL_DRIVE_ENCODER,true,CounterBase::k4X),
		BREnc(BR_DRIVE_ENCODER,true,CounterBase::k4X),
		BLEnc(BL_DRIVE_ENCODER,true,CounterBase::k4X),
		FRPot(FR_ANGLE_POT),
		FLPot(FL_ANGLE_POT),
		BRPot(BR_ANGLE_POT),
		BLPot(BL_ANGLE_POT),
		gyro (GYRO),
		FrontRightAngle(AFR_P, 0, 0, &FRPot, &AFR),
		FrontLeftAngle(AFL_P, 0, .00005, &FLPot, &AFL),
		BackRightAngle(ABR_P, 0, 0, &BRPot, &ABR),
		BackLeftAngle(ABL_P, 0, 0, &BLPot, &ABL),
		FrontRightSpeed(SFR_P, 0, .01, &FREnc, &SFR),
		FrontLeftSpeed(SFL_P, 0, .01, &FLEnc, &SFL),
		BackRightSpeed(SBR_P, 0, .01, &BREnc, &SBR),
		BackLeftSpeed(SBL_P, 0, .01, &BLEnc, &SBL)
	{
		deadband = .1;
		deadbandrad = (PI / 15);
		BackRightAngle.SetAbsoluteTolerance(10);
		FrontLeftAngle.SetAbsoluteTolerance(10);
		FrontRightAngle.SetAbsoluteTolerance(10);
		BackLeftAngle.SetAbsoluteTolerance(10);
		BackRightAngle.SetOutputRange(-.1,.1);
		FrontRightAngle.SetOutputRange(-.1,.1);
		FrontLeftAngle.SetOutputRange(-.5,.5);
		BackLeftAngle.SetOutputRange(-.1,.1);
		BackRightAngle.SetContinuous(true);
		BackLeftAngle.SetContinuous(true);
		FrontLeftAngle.SetContinuous(true);
		toggle = false;
		lasttrigger = 0;
	}
	void Ramping();
	void FindWheelSpeed();
	void Sort();
	void SetWheelSpeed();
	float Sign(float InputSign);
	void FindAngle();
	void SetAngle();
	void SetpointToggle(int trigger);
private:
	float frontrdif, backrdif, frontldif, backldif, FrontLeftOldSpeed, FrontRightOldSpeed, BackLeftOldSpeed, BackRightOldSpeed;
	int lasttrigger;
	bool toggle;

};

#endif
