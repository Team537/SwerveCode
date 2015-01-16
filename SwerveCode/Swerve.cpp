#include "Swerve.h"
#include "Schematic.h"
#include "cmath"
#include "WPILib.h"
#include <Gyro.h>

void Swerve::init(void){
	//FrontLeftAngle.Disable();
	FrontRightAngle.Disable();
	AFR.Set(.5);
	FRPot.GetVoltage();
	if (inittimer.Get() >= 4){
		inittimer.Stop();
		AFR.Set(0);
		FrontRightAngle.Enable();
	}
	SmartDashboard::PutNumber("timer", inittimer.Get());
	double FLpotfeedback = FRPot.GetValue();
	if (FLpotfeedback >= FLpotfeedbackmax){
		FLpotfeedbackmax = FLpotfeedback;
		}
	if (FLpotfeedback <= FLPotfeedbackmin){
		FLPotfeedbackmin = FLpotfeedback;
		}
	SmartDashboard::PutNumber("FLmax", FLpotfeedbackmax);
	SmartDashboard::PutNumber("FLmin", FLPotfeedbackmin);
	SmartDashboard::PutNumber("Potval", FLpotfeedback);
	SmartDashboard::PutNumber("FLPot volts", FRPot.GetVoltage());
}

void Swerve::SetVariables(float Magnitude, float DirectionRadians, float Twist){
	gang = (((gyro.GetAngle())*PI)/180);
	if (fabs(Magnitude) <= deadband){
		Magnitude = 0;
	}
	if (fabs(DirectionRadians) <= deadbandrad){
			DirectionRadians = 0;
	}
	if (fabs(Twist) <= deadband){
			Twist = 0;
	}
	SmartDashboard::PutNumber("Test", 16);
	A = (cos((DirectionRadians-gang))*Magnitude)-(Twist*LENGTH/2);
	B = (cos((DirectionRadians-gang))*Magnitude)+(Twist*LENGTH/2);
	C = (sin((DirectionRadians-gang))*Magnitude)-(Twist*WIDTH/2);
	D = (sin((DirectionRadians-gang))*Magnitude)+(Twist*WIDTH/2);
	SmartDashboard::PutNumber("Test2", 537);
	SmartDashboard::PutNumber("A", A);
	SmartDashboard::PutNumber("B", B);
	SmartDashboard::PutNumber("C", C);
	SmartDashboard::PutNumber("D", D);
	SmartDashboard::PutNumber("Test3", 538);
	
}



void Swerve::FindWheelSpeed(){
	frontlspeed = sqrt((pow(B,2))+(pow(D,2)));
	frontrspeed = sqrt((pow(B,2))+(pow(C,2)));
	backlspeed = sqrt((pow(A,2))+(pow(D,2)));
	backrspeed = sqrt((pow(A,2))+(pow(D,2)));
}

void Swerve::Sort(){
	Ratio = frontlspeed;
	if (Ratio < frontrspeed){
		Ratio = frontrspeed;
	}
	if (Ratio < backlspeed){
		Ratio = backlspeed;
	}
	if (Ratio < backlspeed){
		Ratio = backlspeed;
	}
	if (Ratio > 1){
		frontlspeed/=Ratio;
		frontrspeed/=Ratio;
		backlspeed/=Ratio;
		backrspeed/=Ratio;
		
	}
	SmartDashboard::PutNumber("Test4", 539);
}
void Swerve::Ramping() {
	Sort();
	frontlspeed = LEFT_DRIVE_DIRECTION * frontlspeed;
	frontrspeed = RIGHT_DRIVE_DIRECTION *frontrspeed;
	backlspeed = LEFT_DRIVE_DIRECTION * backlspeed;
	backrspeed = RIGHT_DRIVE_DIRECTION * backrspeed;
	frontldif = frontlspeed - FrontLeftOldSpeed;
	frontrdif = frontrspeed - FrontRightOldSpeed;
	backldif = backlspeed - BackLeftOldSpeed;
	backrdif = backrspeed - BackRightOldSpeed;
	if (fabs(frontldif) >= RAMP_SPEED) {
		FrontLeftOldSpeed += RAMP_SPEED * Sign(frontldif);
	}
	if (fabs(frontrdif) >= RAMP_SPEED) {
		FrontRightOldSpeed += RAMP_SPEED * Sign(frontrdif);
	}
	if (fabs(backldif) >= RAMP_SPEED) {
		BackLeftOldSpeed += RAMP_SPEED * Sign(backldif);
	}
	if (fabs(backrdif) >= RAMP_SPEED) {
		BackRightOldSpeed += RAMP_SPEED * Sign(backrdif);
	}
	if (frontlspeed == 0) {
		FrontLeftOldSpeed = 0;
	}
	if (frontrdif == 0) {
		FrontRightOldSpeed = 0;
	}
	if (frontlspeed == 0) {
		BackLeftOldSpeed = 0;
	}
	if (frontrdif == 0) {
		BackRightOldSpeed = 0;
	}
}
void Swerve::SetWheelSpeed()
{
	//SFL.Set(FrontLeftOldSpeed);
	SFR.Set(FrontRightOldSpeed);
	//SBL.Set(BackLeftOldSpeed);
	//SBR.Set(BackRightOldSpeed);
}
float Swerve::Sign(float InputSign) {
	if (InputSign > 0) {
		return 1;
	}
	if (InputSign < 0) {
		return -1;
	}
	return 0;
}
void Swerve::FindAngle(){
	FLAng = (atan2(B,D)*180/PI)+180;
	FRAng = (atan2(B,C)*180/PI)+180;
	BLAng = (atan2(A,D)*180/PI)+180;
	BRAng = (atan2(A,C)*180/PI)+180;
	SmartDashboard::PutNumber("Front Left Angle", FLAng);
	SmartDashboard::PutNumber("Front Right Angle", FRAng);
	SmartDashboard::PutNumber("Back Left Angle", BLAng);
	SmartDashboard::PutNumber("Back Right Angle", BRAng);
	SmartDashboard::PutNumber("Test 1", 21);
}

void Swerve::SetpointToggle(int trigger)
{

	FrontLeftAngle.Enable();
	/*if(trigger == 1 && lasttrigger == 0){
		if(toggle == true)
		{
			toggle = false;
			FrontRightAngle.SetSetpoint(700);
		}
		else
		{
			toggle =true;
			FrontRightAngle.SetSetpoint(400);
		}
	}
	lasttrigger = trigger;*/
	if (trigger == 1){
		FrontLeftAngle.SetSetpoint(500);
	}
	else
		FrontLeftAngle.SetSetpoint(150);

	SmartDashboard::PutNumber("Front Left input", FLPot.PIDGet());
	SmartDashboard::PutNumber("Front Left output", AFL.Get());
	SmartDashboard::PutNumber("Front Left Error", FrontLeftAngle.GetError());
	SmartDashboard::PutNumber("Front Left input 2", FLPot.PIDGet());
	SmartDashboard::PutNumber("Front Left output 2", AFL.Get());
	SmartDashboard::PutNumber("Front Left Error 2", FrontLeftAngle.GetError());
	SmartDashboard::PutNumber("setpoint left", FrontLeftAngle.GetSetpoint());
	SmartDashboard::PutBoolean("PID On Target", FrontLeftAngle.OnTarget());
	SmartDashboard::PutNumber("FLPot volts", FLPot.GetVoltage());
}

void Swerve::JoystickAngle(float dirictionrad, float mag)
{
	if (fabs(mag) >= .2)
	  drad = dirictionrad+180;
	
}

void Swerve::SetAngle(){
	FrontRightAngle.Enable();
	FrontRightAngle.SetSetpoint(((drad)*(FRRANGE)/360)-FRMIN);
	FrontLeftAngle.Enable();
	FrontLeftAngle.SetSetpoint(((drad)*(FLRANGE)/360)-FLMIN);
	/*BackRightAngle.Enable();
	BackRightAngle.SetSetpoint(BRAng);
	BackLeftAngle.Enable();
	BackLeftAngle.SetSetpoint(BLAng);*/
	if (FrontRightAngle.OnTarget())
		AFR.Set(0);
	if (FrontLeftAngle.OnTarget())
		AFL.Set(0);
	if (BackRightAngle.OnTarget())
		ABR.Set(0);
	
	if (BackLeftAngle.OnTarget())
		ABL.Set(0);
	SmartDashboard::PutNumber("Front Right input", FLPot.PIDGet());
	SmartDashboard::PutNumber("Front Right output", AFL.Get());
	SmartDashboard::PutNumber("Front Right Error", FrontLeftAngle.GetError());
	SmartDashboard::PutNumber("Front Right input 2", FLPot.PIDGet());
	SmartDashboard::PutNumber("Front Right output 2", AFL.Get());
	SmartDashboard::PutNumber("Front Right Error 2", FrontLeftAngle.GetError());
	SmartDashboard::PutNumber("setpoint", FrontLeftAngle.GetSetpoint());
	SmartDashboard::PutBoolean("PID Target", FrontLeftAngle.OnTarget());
	SmartDashboard::PutNumber("FLPot volts", FLPot.GetVoltage());
	SmartDashboard::PutNumber("Gyro Angle", gyro.GetAngle());
}
