#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include "../include/decision_table.h"

int totalTests = 0;
int passedTests = 0;
int failedTests = 0;

void runTest(const char* testName, AvailableSources expected, float sourceA, uint8_t sourceB, float sourceC) {
    totalTests++;
    printf("%s\n",testName);
    AvailableSources result = determineAvailableSources(&sourceA, &sourceB, sourceC);

    if (result == expected) {
        printf(" Test Passed\n");
        passedTests++;
    } else {
        printf(" Test Failed\n");
        printf("  - Input: Source A=%.2f, Source B=%u, Source C=%.2f\n", sourceA, sourceB, sourceC);
        printf("  - Expected: %d, Actual: %d\n", expected, result);
        failedTests++;
    }
}

void test_determineAvailableSources() {
    // Test case 1: Valid sources A, B, and C (Normal case)
    runTest("Test Case 1 : Valid sources A, B, and C", ALL_SOURCES_AVAILABLE, 6.00f, 50, 15.00f);

    // Test case 7: Valid source A, invalid source B and C 
    runTest("Test Case 7 : Valid source A, invalid source B and C", SOURCE_A_ONLY, 6.0f, 0, FLT_MAX);

    // Test case 2: Valid source A, Invalid source B, Valid source C (Normal case)
    runTest("Test Case 2 : Valid source A, Invalid source B, Valid source C", SOURCE_A_AND_C, 6.0f, 120, 15.0f);

    // Test case 4: Valid source A, Valid source B, Invalid source C (Normal case)
    runTest("Test Case 4 : Valid source A, Valid source B, Invalid source C", SOURCE_A_AND_B, 6.0f, 50, 25.5f);

    // Test case 6: Valid source B and C, invalid source A 
    runTest("Test Case 6 : Valid source B and C, invalid source A", SOURCE_B_AND_C, 51.0f, 50, 15.0f);
    
    // Test case 9: Invalid source A, B, and C 
    runTest("Test Case 9 : Invalid source A, B, and C", NO_SOURCE_AVAILABLE, 100.0f, 0, -10.0f);

    // Test case 3: Invalid source A, valid sources B and C (Error Case)
    runTest("Test Case 3 : Invalid source A, valid sources B and C (Error case)", NO_SOURCE_AVAILABLE, -5.0f, 50, 15.0f);

    
    // Test case 5: Valid source A and B, invalid source C (Error case)
    runTest("Test Case 5 : Valid source A and B, invalid source C (Error case)", NO_SOURCE_AVAILABLE, 6.0f, 50, -5.0f);   
   

    // Test case 8: Valid source B, invalid source A and C (Error case)
    runTest("Test Case 8 : Valid source B, invalid source A and C (Error case)", NO_SOURCE_AVAILABLE, -10.0f, 20, -5.0f);

    
    // Test case 12: Valid source B and C, invalid source A (Error case)
    runTest("Test Case 12 : Valid source B and C, invalid source A (Error case)", NO_SOURCE_AVAILABLE, -5.0f, 50, 15.0f);

    // Test case 14: NULL pointers for Source A and B (Error case)
    float *sourceA14 = NULL;
    uint8_t *sourceB14 = NULL;
    runTest("Test Case 14 : NULL pointers for Source A and B (Error case)", NO_SOURCE_AVAILABLE, 0.0f, 0, 0.0f);

    // Test case 15: Invalid A (Edge Case), Valid B, Valid C
    runTest("Test Case 15 : Invalid A (Edge Case), Valid B, Valid C", SOURCE_B_AND_C, FLT_MAX, 50, 15.0f);

    // Test case 16: Valid A, Invalid B (Edge case), Valid C
    runTest("Test Case 16 : Valid A, Invalid B (Edge case), Valid C", SOURCE_A_AND_C, 6.0f, UINT8_MAX, 15.0f);

    // Test case 17: Valid Source A, Valid Source B, Invalid Source C (Edge case)
    runTest("Test Case 17 : Valid Source A, Valid Source B, Invalid Source C (Edge case)", SOURCE_A_AND_B, 6.0f, 50, FLT_MAX);

    // Test case 18: Dereferencing NULL pointer (Error case)
    float *sourceA18 = NULL;
    uint8_t sourceB18 = 50;
    runTest("Test Case 18 : Dereferencing NULL pointer", NO_SOURCE_AVAILABLE, 0.0f, sourceB18, 15.0f);

}

int main(void) {
    // Run the unit tests
    test_determineAvailableSources();

    // Output metrics
    printf("\n----- Test Metrics -----\n");
    printf("Total Tests: %d\n", totalTests);
    printf("Tests Passed: %d\n", passedTests);
    printf("Tests Failed: %d\n", failedTests);

    if (failedTests == 0) {
        printf("\n All tests passed successfully.\n");
        return 0;
    } else {
        printf("\n Some tests failed. See detailed output for more information.\n");
        return 1;
    }
}
