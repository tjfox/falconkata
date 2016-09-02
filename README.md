This is a library to add and subtract roman numerals.

The functions available in this library are:

int add_roman_numeral(const char* operand1,
  const char* operand2, char* result);

int sub_roman_numeral(const char* operand1,
    const char* operand2, char* result);

These functions require the user to provide a result buffer that can contain the
result of the operation. For safety the user will likely want to use
MAX_NUMERAL_LENGTH defined in the library header.

The functions will place the result of the operation in the result buffer and
provide a return the following codes to verify results of the operation.

OK - Operation successful 
INVALID_PARAM - Parameters are invalid 
INVALID_RESULT - Results of the operation are invalid 

The code can be compiled by running make in the root project directory.
After building tests can be run by ./tests/testromannumeralcalculator
