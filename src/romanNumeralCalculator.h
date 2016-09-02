#ifndef ROMANNUMERALCALCULATOR_H
#define ROMANNUMERALCALCULATOR_H

enum op_success_t
{
  OK,
  INVALID_PARAM
};

int add_roman_numeral(const char* operand1,
  const char* operand2, char* result);

#endif /* ROMANNUMERALCALCULATOR_H */
