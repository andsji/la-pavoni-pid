#include "unity.h"
#include "utils.h"
#include <math.h>

#define UNITY_FLOAT_PRECISION (0.0001f)

void setUp() {

}

void tearDown() {

}

void test_get_error() {
    // Arrange
    setPoint = 100;
    float currentTemp = 80;

    // Act
    float calc_error = getError(currentTemp);

    // Assert 
    TEST_ASSERT_EQUAL_INT(20, calc_error); // Check the value of count after one iteration
}

void test_instruction() {
    // Arrange
    float expected_result = 88.8;
    integral_error_acc = 0;
    prev_error = 0;
    error = 80;
    k_p = 1;
    k_i = 0.01;
    k_d = 0.1;

    // Act
    float result = generateInstruction(error);

    // Assert
    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_instruction_negative_error() {
    // Arrange
    float expected_result = 0.0;
    integral_error_acc = 0;
    prev_error = 0;
    error = -80;
    k_p = 1;
    k_i = 0.01;
    k_d = 0.1;

    // Act
    float result = generateInstruction(error);

    // Assert
    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_instruction_large_error() {
    // Arrange
    float expected_result = 100.0;
    integral_error_acc = 0;
    prev_error = 0;
    error = 200;
    k_p = 30;
    k_i = 1;
    k_d = 0.01;

    // Act
    float result = generateInstruction(error);

    // Assert
    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_instruction_no_error() {
    // Arrange
    float expected_result = 0.0;
    integral_error_acc = 0;
    prev_error = 0;
    error = 0;
    k_p = 10;
    k_i = 0.01;
    k_d = 0.1;

    // Act
    float result = generateInstruction(error);

    // Assert
    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_instruction_high_prev_error() {
    // Arrange
    float expected_result = 40.55;
    integral_error_acc = 0;
    prev_error = 100;
    error = 5;
    k_p = 10;
    k_i = 0.01;
    k_d = 0.1;

    // Act
    float result = generateInstruction(error);

    // Assert
    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_integral_error_acc() {
    // Arrange
    float expected_result = 45.0;
    integral_error_acc = 0;
    prev_error = 0;
    error = 50;
    k_p = 10;
    k_i = 0.5;
    k_d = 0.1;

    // Act
    generateInstruction(error);
    error = 40;
    generateInstruction(error);
    float result = integral_error_acc;

    // Assert
    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_get_error);
    RUN_TEST(test_instruction);
    RUN_TEST(test_instruction_negative_error);
    RUN_TEST(test_instruction_large_error);
    RUN_TEST(test_instruction_no_error);
    RUN_TEST(test_instruction_high_prev_error);
    RUN_TEST(test_integral_error_acc);

	UNITY_END();

	return 0;
}

//Mock
void simulateTemperatureChange(Plant* plant, float ssrInstruction, float cycleTime) {}