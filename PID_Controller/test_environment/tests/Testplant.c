#include "unity.h"
#include "plant.h"
#include <math.h>

#define UNITY_FLOAT_PRECISION (0.0001f)

void setUp() {

}

void tearDown() {

}

//Testing with extremely high instruction
void test_temp_change_instr5000() {
	//Arrange
	Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
	float pidInstruction = 5000.0F;
	float cycleTime = 10;
	float expectedTemp = 169.344;

	//Act
	simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
	float actualTemp = testPlant.temp;

	//Assert
	TEST_ASSERT_EQUAL_FLOAT(expectedTemp, actualTemp);
}

void test_temp_change_instr100() {
	//Arrange
	Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
	float pidInstruction = 100.0F;
	float cycleTime = 10;
	float expectedTemp = 23.023;

	//Act
	simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
	float actualTemp = testPlant.temp;

	//Assert
	TEST_ASSERT_EQUAL_FLOAT(expectedTemp, actualTemp);
}

void test_temp_change_instr50() {
	//Arrange
	Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
	float pidInstruction = 50.0F;
	float cycleTime = 10;
	float expectedTemp = 21.530;

	//Act
	simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
	float actualTemp = testPlant.temp;

	//Assert
	TEST_ASSERT_EQUAL_FLOAT(expectedTemp, actualTemp);
}

void test_temp_change_instr0() {
	//Arrange
	Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
	float pidInstruction = 0.0F;
	float cycleTime = 10;
	float expectedTemp = 20.037;

	//Act
	simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
	float actualTemp = testPlant.temp;

	//Assert
	TEST_ASSERT_EQUAL_FLOAT(expectedTemp, actualTemp);
}

void test_temp_change_instr_negative() {
	//Arrange
	Plant testPlant = { 20.0, 0.8, 4186.0, 1000.0, 1000.0, 14.0, 4.45, 0.00623, 22.0 };
	float pidInstruction = -100.0F;
	float cycleTime = 10;
	float expectedTemp = 17.051;

	//Act
	simulateTemperatureChange(&testPlant, pidInstruction, cycleTime);
	float actualTemp = testPlant.temp;

	//Assert
	TEST_ASSERT_EQUAL_FLOAT(expectedTemp, actualTemp);
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_temp_change_instr5000);
	RUN_TEST(test_temp_change_instr100);
	RUN_TEST(test_temp_change_instr50);
	RUN_TEST(test_temp_change_instr0);
	RUN_TEST(test_temp_change_instr5000);
	RUN_TEST(test_temp_change_instr_negative);


	UNITY_END();

	return 0;
}
