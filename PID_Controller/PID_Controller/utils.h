#ifndef UTILS_H
#define UTILS_H

#define HARDWARE
#ifndef HARDWARE
	#define SIMULATION
	#include "Simulation/plant.h"
#else
	#include <Arduino.h>
	#include <max6675.h>
	#include <LiquidCrystal_I2C.h>
	#include <Wire.h>
#endif

	extern float setPoint;
	extern float error;
	extern float prev_error;

	extern float cycleTime; 
	extern float cycleTimeMs; 

	extern float k_p; 
	extern float k_i; 
	extern float k_d; 

	extern float integral_error_acc; 

	float getTemperature();
	float getError(float receivedTemp);
	float generateInstruction(float error);
	void actuator(float instr);

#endif