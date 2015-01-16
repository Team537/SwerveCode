#include "Schematic.h"
#include "SwerveModule.h"
#include "cmath"

void SwerveModule::Initialize()
{
	//SmartDashboard::PutData("Angle PID", PIDAngle);
}

void SwerveModule::drive(float angle, float speed)
{
	if (fabs(angle) < JOYDEADBAND)
	{
		angle = 0;
	}

	if (fabs(speed) < JOYDEADBAND)
	{
		speed = 0;
	}
	
	AngleOutput->Set(angle);
	SpeedOutput->Set(speed);
	double potfeedback = AnglePotentiometer->PIDGet();
		if (potfeedback >= potfeedbackmax){
			potfeedbackmax = potfeedback;
			}
		if (potfeedback <= potfeedbackmin){
			potfeedbackmin = potfeedback;
			}
	SmartDashboard::PutNumber("max pot", potfeedbackmax);
	SmartDashboard::PutNumber("min pot", potfeedbackmin);
	SmartDashboard::PutNumber(Name+ "Potval", potfeedback);
	SmartDashboard::PutNumber("Encoder", SpeedEncoder->GetRate());
	SmartDashboard::PutNumber("Potentiometer", AnglePotentiometer->GetValue());
	SmartDashboard::PutNumber("Angle IO",angle);
	SmartDashboard::PutNumber("Speed IO",speed);
}

void SwerveModule::AutoDrive(float Angle)
{

	PIDAngle->Enable();
	PIDAngle->SetSetpoint(Angle);
	SmartDashboard::PutNumber(Name+ "PotReading", AnglePotentiometer->PIDGet());
	SmartDashboard::PutNumber(Name+ "Angle Error", PIDAngle->GetError());
	SmartDashboard::PutNumber(Name+ "Angle Setpoint", PIDAngle->GetSetpoint());
	SmartDashboard::PutBoolean(Name+ "Angle Target", PIDAngle->OnTarget());
	SmartDashboard::PutNumber(Name+ "Angle Error2", PIDAngle->GetError());
}
void SwerveModule::PIDAdjust(float P, float I, float D)
{
	SmartDashboard::PutNumber(Name+ "P", PIDAngle->GetP());
	SmartDashboard::PutNumber(Name+ "I", PIDAngle->GetI());
	SmartDashboard::PutNumber(Name+ "D", PIDAngle->GetD());
	PIDAngle->SetPID(P, I, D);
}

