#ifndef POTENTIOMETERTHREESIXTY_H
#define POTENTIOMETERTHREESIXTY_H

#include "Schematic.h"
#include "WPILib.h"
#include "AnalogChannel.h"

class PotentiometerThreeSixty : public AnalogChannel
{
	public:
		PotentiometerThreeSixty(uint8_t moduleNumber, uint32_t channel);
		double PIDGet();
		double getmax();
		double getmin();
	private:
		double vmin,vmax;
		
};
#endif
