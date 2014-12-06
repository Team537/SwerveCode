#ifndef POTENTIOMETERTHREESIXTY_H
#define POTENTIOMETERTHREESIXTY_H

#include "Schematic.h"
#include "WPILib.h"
#include "AnalogChannel.h"

class PotentiometerThreeSixty : public AnalogChannel
{
	public:
		PotentiometerThreeSixty(uint8_t moduleNumber, uint32_t channel);
		inline void SetMinMax(double min, double max) {m_vmin = min; m_vmax = max;};
		double GetVoltage();
		void CalcAng();
		double getmax();
		double getmin();
	private:
		double m_vmin, m_vmax, m_conv, m_ang, m_volt;
		
};
#endif

