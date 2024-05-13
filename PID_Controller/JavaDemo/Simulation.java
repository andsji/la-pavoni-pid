public class Simulation {
    public static void main(String[] args) {
        final int startTemp = 20;

        Plant laPavoni = new Plant(startTemp);
        Controller controller = new Controller(96.0, 5, 0.1, 0.01);

        Controlsystem system = new Controlsystem(controller, laPavoni);

        System.out.println("Starting temperature: " + startTemp);
        System.out.println("Temperature goal: " + controller.setpoint);

        system.control();
    }
}

class Controller {
    public double setpoint;
    public double error;
    public double prev_error;
    public double kfactor_p;
    public double kfactor_i;
    public double kfactor_d;
    public double integral_error_acc;
    public double derivative_error;

    public Controller(double setpoint, double kfactor_p, double kfactor_i, double kfactor_d) {
        this.setpoint = setpoint;
        this.kfactor_p = kfactor_p;
        this.kfactor_i = kfactor_i;
        this.kfactor_d = kfactor_d;
        this.error = 0;
        this.prev_error = 0;
        this.integral_error_acc = 0;
        this.derivative_error = 0;
    }

    public double generateInstruction(boolean p, boolean i, boolean d) {
        double controllerInstruction = 0;
        
        if (p) {
            controllerInstruction += proportional(error);
        }
        if (i) {
            controllerInstruction += integral(error);
        }
        if (d) {
            controllerInstruction += derivative(error, prev_error);
            prev_error = error; // Update prev_error after derivative calculation
        }
        
        // make sure the instruction is within the range 0-100 before returning.
        if (controllerInstruction > 100) {
            controllerInstruction = 100;
        } else if (controllerInstruction < 0) {
            controllerInstruction = 0;
        }

        return controllerInstruction;
    }

    public void setError(double feedback) {
        this.prev_error = this.error; // Move this line here to correctly track previous error
        this.error = this.setpoint - feedback;
    }

    public double proportional(double error) {
        return error * kfactor_p;
    }

    public double integral(double error) {
        integral_error_acc += error * kfactor_i;
        return integral_error_acc;
    }

    public double derivative(double error, double prev) {
        derivative_error = (error - prev) * kfactor_d;
        return derivative_error;
    }
}

class Plant {
    public double temperature; //Temperature of water in boiler.

    private static final double mass = 0.8; // Mass of water in kg
    private static final double specificHeatCapacity = 4186; // Specific heat capacity of water in J/kg°C
    private static final double power = 1000; // Power of the heating element in watts
    private static final double cycleTime = 10; // Duration of each control cycle in seconds

    private static final double htc = 1000; //Heat Transfer Coefficient (Should NOT be a static value in final simulation)

    private static final double cylinderHeight = 14; //In centimeters
    private static final double cylinderRadius = 4.45; //In centimeters
    private static final double surfaceArea = (cylinderHeight*cylinderRadius) / 10000; //Surface area of cylindrical boiler in m2.

    private static final double ambientTemp = 22; //Room temperature for heat loss calculation.


    public Plant(double temperature) {
        this.temperature = temperature;
    }

    public double getFeedback(double pidOutput) {
        return simulateTemperatureChange(pidOutput);
    }

    public double simulateTemperatureChange(double instruction) {
    
        // Calculate the effective power based on the PID output
        double effectivePower = power * (instruction / 100.0); // Convert percentage to a fraction

        // Calculate the energy added to the water in one cycle
        double energyAdded = effectivePower * cycleTime; // Q = P * t

        //Calculate heat loss
        double heatLoss = htc * surfaceArea * (temperature - ambientTemp) * cycleTime;

        //Re-calculate energy with heat loss taken into account
        energyAdded -= heatLoss; //

        // Calculate the temperature increase for this energy
        double tempIncrease = energyAdded / (mass * specificHeatCapacity);

        // Update the temperature of the water
        temperature += tempIncrease;

        return temperature;
    }
}


class Controlsystem {
    private final Controller controller;
    private final Plant plant;

    public Controlsystem(Controller controller, Plant plant) {
        this.controller = controller;
        this.plant = plant;
    }

    public void control() {
        for (int i = 0; i < 100; i++) {
            double feedback = plant.temperature;
            controller.setError(feedback);
            double instruction = controller.generateInstruction(true, true, true);
            plant.getFeedback(instruction);
            System.out.println("Cycle: " + i);
            System.out.println("Temperature: " + String.format("%.2f", plant.temperature));
            System.out.println("Instruction: " + String.format("%.2f", instruction));
            System.out.println("-------------------------------");
        }
    }
}
