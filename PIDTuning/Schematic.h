#ifndef SCHEMATIC_H
#define SCHEMATIC_H

//Constants
#define JOYDEADBAND .25

//Victors
#define FLA_VICTOR 1,5
#define FRA_VICTOR 1,6
#define LA_VICTOR 1,2
#define RA_VICTOR 1,3
#define FLD_VICTOR 1,1
#define FRD_VICTOR 1,8
#define LD_VICTOR 1,4
#define RD_VICTOR 1,7

//Kintroller
#define CONTROLLER 1


//Analog Inputs
#define LENC 1,5,1,6
#define RENC 1,3,1,4

//PID
#define LP 0.00005
#define RP -0.00005

#define MAX_RATE_RIGHT 117.443
#define MAX_RATE_LEFT 117.443

// comp
#define COMPRESSOR_SWITCH 1,1
#define COMPRESSOR_RELAY 1,2

#endif
