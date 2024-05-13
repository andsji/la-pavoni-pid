#include "../controlsystem.h"
#ifdef HARDWARE
//Do nothing
#else

TaskHandle_t ReadTemperatureTask;
TaskHandle_t PIDInstructionTask;
TaskHandle_t PowerControlTask;

extern QueueHandle_t temperatureQueue;
extern QueueHandle_t instructionQueue;

int main(void) {

    temperatureQueue = xQueueCreate(1, sizeof(float));
    if (temperatureQueue == NULL) {
        //printf("%s", "Failed to create tempQueue");
    }

    instructionQueue = xQueueCreate(1, sizeof(float));
    if (instructionQueue == NULL) {
        //printf("%s", "Failed to create instructionQueue");
    }

    xTaskCreate(
        ReadTemperature,
        "Read Temperature",
        10*configMINIMAL_STACK_SIZE,
        NULL,
        1,
        &ReadTemperatureTask
    );

    xTaskCreate(
        PIDInstruction,
        "Generate PID Instruction",
        10*configMINIMAL_STACK_SIZE,
        NULL,
        2,
        &PIDInstructionTask
    );

    xTaskCreate(
        PowerControl,
        "Update Temperature",
        10*configMINIMAL_STACK_SIZE,
        NULL,
        3,
        &PowerControlTask
    );

    vTaskStartScheduler();

    for (;;);
}

#endif