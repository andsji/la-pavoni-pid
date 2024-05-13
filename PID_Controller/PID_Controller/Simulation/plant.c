#include "plant.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    void simulateTemperatureChange(Plant* plant, float ssrInstruction, float cycleTime) {
        float effectivePower = plant->power * (ssrInstruction / 100.0f); // Convert percentage to a fraction

        // Calculate the energy added to the water in one cycle
        float energyAdded = effectivePower * cycleTime; // Q = P * t

        //Calculate heat loss
        float heatLoss = plant->htc * plant->surfaceArea * (plant->temp - plant->ambientTemp) * cycleTime;

        //Re-calculate energy with heat loss taken into account
        energyAdded -= heatLoss; //

        // Calculate the temperature increase for this energy
        float tempIncrease = energyAdded / (plant->mass * plant->specificHeatCapacity);

        // Update the temperature of the water
        plant->temp += tempIncrease;

        //printf("Succesful call of simulateTemperatureChange, temp: ");
        //printf("%f\n", plant->temp);
    }

#ifdef __cplusplus
}
#endif