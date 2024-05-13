#define HARDWARE
#include <max6675.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "controlsystem.h"

// Define the pins for the thermocouple
int thermoDO = 19;
int thermoCS = 23;
int thermoCLK = 5;

int ssr = 13;

TaskHandle_t ReadTemperatureTask;
TaskHandle_t PIDInstructionTask;
TaskHandle_t PowerControlTask;
extern QueueHandle_t temperatureQueue;
extern QueueHandle_t instructionQueue;

extern LiquidCrystal_I2C lcd;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(ssr, OUTPUT);

  delay(500);

  temperatureQueue = xQueueCreate(1, sizeof(float));
    if (temperatureQueue == NULL) {
        printf("%s", "Failed to create tempQueue");
    }

  instructionQueue = xQueueCreate(1, sizeof(float));
    if (instructionQueue == NULL) {
        printf("%s", "Failed to create instructionQueue");
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
        "Control the SSR",
        10*configMINIMAL_STACK_SIZE,
        NULL,
        3,
        &PowerControlTask
    );


}

void loop() {

}
