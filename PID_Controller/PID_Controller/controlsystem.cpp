#include "controlsystem.h" 

#include <iostream> 

QueueHandle_t temperatureQueue;
QueueHandle_t instructionQueue;

void ReadTemperature(void *param) {
    for (;;) {
        float temperature = getTemperature();
        xQueueSend(temperatureQueue, &temperature, portMAX_DELAY);
        // Wait for x milliseconds
        vTaskDelay(cycleTimeMs / portTICK_PERIOD_MS);
        // Delay should be set to cycleTimeMs, but can be set to less to output quicker if running the simulation.
    }
}

void PIDInstruction(void *param) {
    for (;;) {
        float receivedTemperature;
        float instruction = 0;
        if (xQueueReceive(temperatureQueue, &receivedTemperature, portMAX_DELAY) == pdPASS) {

            error = getError(receivedTemperature);
            
            //Log to .csv file
            //logErrorData(receivedTemperature);

            instruction = generateInstruction(error);

            xQueueSend(instructionQueue, &instruction, portMAX_DELAY);
        }
    }
}

void PowerControl(void *param) {
    for (;;) {
        float pid_instruction;
        if (xQueueReceive(instructionQueue, &pid_instruction, portMAX_DELAY) == pdPASS) {
            
            actuator(pid_instruction);
        }
    }
}

//Log data for tuning & graphing
/*void logErrorData(float error) {
    FILE* fp;
    errno_t err = fopen_s(&fp, "pid_setpoint96_kp30_ki0.001_kd0.01_sim.csv", "a");
    if (err != NULL) {
        printf("Error opening file.");
        return;
    }

    fprintf(fp, "%.2f\n", error);

    fclose(fp);
}
*/