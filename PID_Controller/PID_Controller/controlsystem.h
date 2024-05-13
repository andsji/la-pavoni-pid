#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H
#include "utils.h"

#ifdef SIMULATION
	#include "Simulation/FreeRTOS_Port/FreeRTOS.h"
	#include "Simulation/FreeRTOS_Port/FreeRTOSConfig.h"
	#include "Simulation/FreeRTOS_Port/task.h"
	#include "Simulation/FreeRTOS_Port/timers.h"
	#include "Simulation/FreeRTOS_Port/queue.h"
#else
	#include <Arduino.h>
#endif

	extern int count;

	void ReadTemperature(void* param);
	void PIDInstruction(void* param);
	void PowerControl(void* param);
	//void logErrorData(float error);

#endif