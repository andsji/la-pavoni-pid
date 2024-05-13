#ifndef PLANT_H
#define PLANT_H

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct Plant {
		float temp;
		float mass; //Mass of water in kg (800 ml)
		float specificHeatCapacity;
		float power; //Power of heating element in watts
		float htc; //Heat transfer coefficient
		float cylinderHeight; //In cm
		float cylinderRadius; //In cm
		float surfaceArea; //Surface area of cylindrical boiler in m^2
		float ambientTemp; //Room temp for heat loss calc
	} Plant;

	//Declaration of method that simulates change in temperature.
	void simulateTemperatureChange(Plant* plant, float ssrInstruction, float cycleTime);

#ifdef __cplusplus
}
#endif
#endif