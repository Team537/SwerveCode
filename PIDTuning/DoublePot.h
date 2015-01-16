#ifndef DOUBLEPOT_H

#include "Schematic.h"
#include "WPILib.h"
#include "AnalogChannel.h"

class DoublePot : public AnalogChannel
{
public:
	DoublePot(uint8_t moduleNumber, uint32_t channel, float min, float max, float Offset); 
	double PIDGet();
private:
	bool alternater;
	bool lastdeltasign;
	double lastval;
	float Min;
	float Max;
	int counter;
	double accum;
	double OFFSet;
};
#endif
