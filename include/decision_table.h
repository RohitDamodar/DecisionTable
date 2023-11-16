#ifndef DECISION_TABLE_H
#define DECISION_TABLE_H

#include <stdint.h>

/* Enumeration for the available sources */
typedef enum {
    NO_SOURCE_AVAILABLE = 0,
    SOURCE_C_ONLY,
    SOURCE_B_ONLY,
    SOURCE_B_AND_C,
    SOURCE_A_ONLY,
    SOURCE_A_AND_C,
    SOURCE_A_AND_B,
    ALL_SOURCES_AVAILABLE
} AvailableSources;

/**
 * @brief Determines the available sources based on inputs.
 *
 * This function checks the validity of input values and resolutions
 * for Source A, Source B, and Source C. It then determines the
 * available sources using a switch statement based on the validity
 * of input values.
 *
 * @param sourceA Pointer to Source A value.
 * @param sourceB Pointer to Source B value.
 * @param sourceC Value for Source C.
 *
 * @return Enumeration representing the available sources.
 */
AvailableSources determineAvailableSources(float *sourceA, uint8_t *sourceB, float sourceC);

#endif  // DECISION_TABLE_H
