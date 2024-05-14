# PID Controller for Espresso Machine

A PID controller built for the La Pavoni Europiccola.
The system utilizes FreeRTOS for task prioritization.

## How to use

The PID controller is tuned for the La Pavoni Europiccola's full boiler capacity of 800 ml of water.

The following hardware parts are used and needed in this setup:

* ESP32 DevKit Microcontroller
* MAX6675 K-Type Thermocouple
* Fortek SSR-40DA
* An I2C compatible LCD Display
* An extension cord, if you wish to keep the La Pavoni power cord intact.

The image below shows the wiring used.

![Wiring](https://github.com/andsji/la-pavoni-pid/raw/main/.readme/wiring.png)

The pins used can be seen, and optionally changed, in the [PID_Controller.ino](https://github.com/andsji/la-pavoni-pid/raw/main/PID_Controller/PID_Controller/PID_Controller.ino) file.

For optimal use (to avoid heat- and pressure loss), drill a hole in the machine's lid. Insert the thermocouple and seal the hole properly, e.g. with waterproof silicone gel.

The set point and gain factors can be changed in the [utils.cpp](https://github.com/andsji/la-pavoni-pid/raw/main/PID_Controller/PID_Controller/utils.cpp) file:

```
float setPoint = 96.0;
...
float k_p = 30.00F; 
float k_i = 0.001F; 
float k_d = 0.1F; 
```

## How to run simulation

To simulate the behavior of the control system, simply comment out the _#define HARDWARE_ line in the [utils.h](https://github.com/andsji/la-pavoni-pid/raw/main/PID_Controller/PID_Controller/utils.h) file.

The simulation must be built and run in Visual Studio 2019 for Windows due to the dependancies of the FreeRTOS Windows Port.