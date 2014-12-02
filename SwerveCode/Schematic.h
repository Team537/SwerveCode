#ifndef SCHEMATIC_H
#define SCHEMATIC_H

//Constants
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
#define RAMP_SPEED .1
#define LEFT_DRIVE_DIRECTION 1
#define RIGHT_DRIVE_DIRECTION -1
#define VOLTCONVERTER 79.03402854006586
#define ADJUSTER .198

//Compressor
#define COMPRESSOR_SWITCH 1,2
#define COMPRESSOR_RELAY 1,1

//Victors
#define FL_DRIVE_VICTOR 1,10
#define FR_DRIVE_VICTOR 1,9
#define BL_DRIVE_VICTOR 1,5
#define BR_DRIVE_VICTOR 1,6
#define FL_ANGLE_VICTOR 1,2
#define FR_ANGLE_VICTOR 1,1
#define BL_ANGLE_VICTOR 1,4
#define BR_ANGLE_VICTOR 1,3

//Kintroller
#define CONTROLLER 1

//Frame
#define LENGTH 27.5
#define WIDTH 23

//Digital Inputs
#define FL_DRIVE_ENCODER 1,1
#define FR_DRIVE_ENCODER 1,2
#define BL_DRIVE_ENCODER 1,4
#define BR_DRIVE_ENCODER 1,3


//Digital Outputs


//Analog Inputs
#define FL_ANGLE_POT 1,5
#define FR_ANGLE_POT 1,4
#define BR_ANGLE_POT 1,3
#define BL_ANGLE_POT 1,6

//Anolog Outputs
#define GYRO 1,1

//Joystick

#define ZAXIS 3

//PID
#define AFL_P .00001
#define AFR_P .00001
#define ABL_P .000001
#define ABR_P .000001
#define SFL_P .001
#define SFR_P .001
#define SBL_P .001
#define SBR_P .001

#endif
