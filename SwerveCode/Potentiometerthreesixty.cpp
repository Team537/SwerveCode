#include "Potentiometerthreesixty.h"
#include "WPILib.h"
#include "Schematic.h"

PotentiometerThreeSixty::PotentiometerThreeSixty(uint8_t moduleNumber, uint32_t channel) : AnalogChannel(moduleNumber, channel)
{
	m_vmin = 0; 
	m_vmax = 1;
	CalcAng();
}
double PotentiometerThreeSixty::GetVoltage()
{
	//SmartDashboard::PutNumber("Analog voltage get" , AnalogChannel::GetVoltage());
	double voltage = AnalogChannel::GetVoltage();
	if (voltage >= m_vmax){
		m_vmax = voltage;
	}
	if (voltage <= m_vmin){
		m_vmin = voltage;
	}
	CalcAng();
	return m_ang;
}
void PotentiometerThreeSixty::CalcAng()
{
	m_conv = 360/(m_vmax-m_vmin);
	m_volt = AnalogChannel::GetVoltage();
	m_ang  = (m_conv * (m_volt - m_vmin));
}
double PotentiometerThreeSixty::getmin(){
	return m_vmin;
}
double PotentiometerThreeSixty::getmax(){
	return m_vmax;
}
