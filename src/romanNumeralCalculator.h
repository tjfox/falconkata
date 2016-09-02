#ifndef ROMANNUMERALCALCULATOR_H
#define ROMANNUMERALCALCULATOR_H

static const int MAX_NUMERAL_LENGTH = 15;

enum op_success_t
{
  OK,
  INVALID_PARAM,
  INVALID_RESULT
};

int add_roman_numeral(const char* operand1,
  const char* operand2, char* result);

int sub_roman_numeral(const char* operand1,
    const char* operand2, char* result);


#endif /* ROMANNUMERALCALCULATOR_H */
