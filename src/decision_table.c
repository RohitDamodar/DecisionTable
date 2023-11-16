#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include <math.h>
#include "../include/decision_table.h"

AvailableSources determineAvailableSources(float *sourceA, uint8_t *sourceB, float sourceC) {
    // Check for NULL pointers
    if (sourceA == NULL || sourceB == NULL) {
        fprintf(stderr, "Error: Invalid input pointers.\n");
        return NO_SOURCE_AVAILABLE;
    }

    // Check for invalid resolutions
    const float resolutionA = 0.01f;
    const uint8_t resolutionB = 1;
    const float resolutionC = 0.01f;

    // Define input value ranges
    const float min_lenA = 0.00f;
    const float max_lenA = 12.00f;
    const uint8_t min_lenB = 1;
    const uint8_t max_lenB = 100;
    const float min_lenC = 1.00f;
    const float max_lenC = 20.00f;

    // Check for valid data types and overflow
    if (*sourceA < FLT_MIN || *sourceA > FLT_MAX) {
        fprintf(stderr, "Error: Invalid data type or overflow for Source A.\n");
        return NO_SOURCE_AVAILABLE;
    }

    if (*sourceB > UINT8_MAX) {
        fprintf(stderr, "Error: Value overflow for Source B.\n");
        return NO_SOURCE_AVAILABLE;
    }

    if (sourceC < FLT_MIN || sourceC > FLT_MAX) {
        fprintf(stderr, "Error: Invalid data type or overflow for Source C.\n");
        return NO_SOURCE_AVAILABLE;
    }

    // Determine availability based on input values
    int isSourceAValid = (*sourceA >= min_lenA && *sourceA <= max_lenA);
    int isSourceBValid = (*sourceB >= min_lenB && *sourceB <= max_lenB);
    int isSourceCValid = (sourceC >= min_lenC && sourceC <= max_lenC);

    // Determine the available sources using a switch statement
    switch ((isSourceAValid << 2) | (isSourceBValid << 1) | isSourceCValid) {
        case 7:
            return ALL_SOURCES_AVAILABLE;
        case 6:
            return SOURCE_A_AND_B;
        case 5:
            return SOURCE_A_AND_C;
        case 3:
            return SOURCE_B_AND_C;
        case 4:
            return SOURCE_A_ONLY;
        case 2:
            return SOURCE_B_ONLY;
        case 1:
            return SOURCE_C_ONLY;
        default:
            return NO_SOURCE_AVAILABLE;
    }
}

/*
int main() {
    // Example usage of the decision table code
    float exampleSourceA = 6.0f;
    uint8_t exampleSourceB = 50;
    float exampleSourceC = 15.0f;

    AvailableSources result = determineAvailableSources(&exampleSourceA, &exampleSourceB, exampleSourceC);

    // Print the result
    printf("Available Sources: %d\n", result);

    return 0;
}
*/
