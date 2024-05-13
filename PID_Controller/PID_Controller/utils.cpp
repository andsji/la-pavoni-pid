#include "utils.h"

#ifdef SIMULATION
    Plant plant = { 22.0F, 0.8F, 4184.0F, 809.06F, 21.145F, 18.0F, 4.0F, 0.0553F, 22.0F };
    #include <iostream>
#else
    extern int thermoDO;
    extern int thermoCS;
    extern int thermoCLK;

    extern int ssr;

    MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
    LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif

float setPoint = 96.0;
float error = 0;
float prev_error = 0; //Previous error
float integral_error_acc = 0; //Accumulated integral error value

float k_p = 30.00F; //P controller gain
float k_i = 0.001F; //I controller gain
float k_d = 0.1F; //D controller gain

float cycleTime = 1; //In seconds
float cycleTimeMs = 1 * 1000.0; //Seconds converted to ms

float generateInstruction(float error) {
    float instruction = 0;

    //Calculate P instruction
    instruction += error * k_p;

    //Calculate I instruction
    integral_error_acc += error * k_i;
    instruction += integral_error_acc;

    //Calculate D instruction
    instruction += (error - prev_error) * k_d;

    prev_error = error;

    if (instruction > 100) {
        instruction = 100;
    }
    else if (instruction < 0) {
        instruction = 0;
    }

    return instruction;
}

float getError(float receivedTemp) {
    float error;
    error = setPoint - receivedTemp;
    return error;
}

float getTemperature() {
#ifdef SIMULATION
    return plant.temp;
#else
    float readtemp = thermocouple.readCelsius();
  
    Serial.println(readtemp); 

    lcd.clear();
    lcd.print("Temp : ");
    lcd.print(readtemp);
    lcd.print((char)223);
    lcd.print("C");

    return readtemp;
#endif
}

void actuator(float instr) {
#ifdef SIMULATION
    simulateTemperatureChange(&plant, instr, cycleTime);

    std::cout << "Temperature: " << plant.temp << "\n";
#else 
    float onTime = (instr / 100) * cycleTimeMs;

    lcd.setCursor(0, 1); //print on next line
    lcd.print("Instr: ");
    lcd.print(instr);

    digitalWrite(ssr, HIGH);
    delay(onTime);

    // Best for the espresso machine to not turn off for a fraction of a second each cycle
    if (onTime < cycleTimeMs) {
        float offTime = cycleTimeMs - onTime;

        digitalWrite(ssr, LOW);
        delay(offTime);
    }
#endif
}