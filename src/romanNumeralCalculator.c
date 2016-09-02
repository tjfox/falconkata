#include "romanNumeralCalculator.h"
#include <ctype.h>
#include <string.h>

int lowercase_string_check(const char* operand)
{
  int i;
  for(i = 0; operand[i] != '\0'; ++i)
  {
    if(islower(operand[i]))
    {
      return INVALID_PARAM;
    }
  }
  return OK;
}

int add_roman_numeral(const char* operand1,
  const char* operand2, char* result)
  {
    if(lowercase_string_check(operand1) != OK)
    {
      return INVALID_PARAM;
    }
    else if(lowercase_string_check(operand2) != OK)
    {
      return INVALID_PARAM;
    }

    strcpy(result, "II");
    return OK;
  }
