#include "pch.h"
#include "gtest/gtest.h"
#include "../PID_Controller/PID_Controller/utils.h"
#include "../PID_Controller/PID_Controller/utils.cpp"
#include "../PID_Controller/PID_Controller/Simulation/plant.h"
#include "../PID_Controller/PID_Controller/Simulation/plant.c"

namespace Tests {

    TEST(ErrorTest, GetError) {
        setPoint = 100;
        float currentTemp = 80;

        float calc_error = getError(currentTemp);

        EXPECT_EQ(20, calc_error);
    }

    TEST(InstructionTest, StandardError) {
        float expected_result = 88.8;
        integral_error_acc = 0;
        prev_error = 0;
        error = 80;
        k_p = 1.0;
        k_i = 0.01;
        k_d = 0.1;

        float result = generateInstruction(error);

        EXPECT_EQ(expected_result, result);
    }

    TEST(InstructionTest, NegativeError) {
        float expected_result = 0.0;
        integral_error_acc = 0;
        prev_error = 0;
        error = -80;
        k_p = 1.0;
        k_i = 0.01;
        k_d = 0.1;

        float result = generateInstruction(error);

        EXPECT_EQ(expected_result, 0.0);
    }

    TEST(InstructionTest, LargeError) {
        float expected_result = 100.0;
        integral_error_acc = 0;
        prev_error = 0;
        error = 200;
        k_p = 30;
        k_i = 1;
        k_d = 0.01;

        float result = generateInstruction(error);

        EXPECT_EQ(expected_result, 100.0);
    }

    TEST(InstructionTest, NoError) {
        float expected_result = 0.0;
        integral_error_acc = 0;
        prev_error = 0;
        error = 0;
        k_p = 10;
        k_i = 0.01;
        k_d = 0.1;

        float result = generateInstruction(error);

        EXPECT_EQ(expected_result, result);
    }

    TEST(InstructionTest, HighPrevError) {
        float expected_result = 40.55;
        integral_error_acc = 0;
        prev_error = 100;
        error = 5;
        k_p = 10;
        k_i = 0.01;
        k_d = 0.1;

        float result = generateInstruction(error);

        EXPECT_EQ(expected_result, result);
    }

    TEST(ErrorTest, IntegralErrorAcc) {
        float expected_result = 45.0;
        integral_error_acc = 0;
        prev_error = 0;
        error = 50;
        k_p = 10;
        k_i = 0.5;
        k_d = 0.1;

        generateInstruction(error);
        error = 40;
        generateInstruction(error);
        float result = integral_error_acc;

        EXPECT_EQ(expected_result, result);
    }

    float float_precision = 0.001f;

    TEST(TemperatureTest, Instruction100) {
        Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
        float pidInstruction = 100.0F;
        float cycleTime = 10;
        float expectedTemp = 23.023;

        simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
        float actualTemp = testPlant.temp;

        ASSERT_NEAR(expectedTemp, actualTemp, float_precision);
    }

    TEST(TemperatureTest, Instruction50) {
        Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
        float pidInstruction = 50.0F;
        float cycleTime = 10;
        float expectedTemp = 21.530;

        simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
        float actualTemp = testPlant.temp;

        ASSERT_NEAR(expectedTemp, actualTemp, float_precision);
    }

    TEST(TemperatureTest, Instruction5000) {
        Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
        float pidInstruction = 5000.0F;
        float cycleTime = 10;
        float expectedTemp = 169.344;

        simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
        float actualTemp = testPlant.temp;

        ASSERT_NEAR(expectedTemp, actualTemp, float_precision);
    }

    TEST(TemperatureTest, Instruction0) {
        Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
        float pidInstruction = 0.0F;
        float cycleTime = 10;
        float expectedTemp = 20.037;

        simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
        float actualTemp = testPlant.temp;

        ASSERT_NEAR(expectedTemp, actualTemp, float_precision);
    }

    TEST(TemperatureTest, NegativeInstruction) {
        Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
        float pidInstruction = -100.0F;
        float cycleTime = 10;
        float expectedTemp = 17.051;

        simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
        float actualTemp = testPlant.temp;

        ASSERT_NEAR(expectedTemp, actualTemp, float_precision);
    }

    int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    
}