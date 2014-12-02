#include "Potentiometerthreesixty.h"
#include "WPILib.h"
#include "Schematic.h"

PotentiometerThreeSixty::PotentiometerThreeSixty(uint8_t moduleNumber, uint32_t channel)
	: AnalogChannel(moduleNumber, channel){
	vmin = 2;
	vmax = 2;
	}
double PotentiometerThreeSixty::PIDGet()
{
	//SmartDashboard::PutNumber("Analog voltage get" , AnalogChannel::GetVoltage());
	double voltage = AnalogChannel::GetVoltage();
	if (voltage >= vmax){
		vmax = voltage;
	}
	if (voltage <= vmin){
		vmin = voltage;
	}
	return (AnalogChannel::GetVoltage()-ADJUSTER)*VOLTCONVERTER;
}
double PotentiometerThreeSixty::getmin(){
	return vmin;
}
double PotentiometerThreeSixty::getmax(){
	return vmax;
}