# Decision Table Code
@Author Rohit Damodar (drohit@umich.edu)

## Overview

The decision table code determines the available sources based on input values for Source A, Source B, and Source C. The availability is determined by checking the validity of the input values and resolutions.

## Directory Structure

decision_table/
|-- include/
| |-- decision_table.h # Header file for the decision table code
|-- src/
| |-- decision_table.c # Source code for the decision table functionality
|-- test/
| |-- test_decision_table.c # Unit test code
|-- build/
| |-- decision_table_executable # Executable file for the decision table code
| |-- test_executable # Executable file for the unit tests
|-- README.md # Main README file for the project

## Compile and Run the Unit Test Cases

$ gcc -o build/test_executable src/decision_table.c test/test_decision_table.c -I./include -lm

$ ./build/decision_table_executable