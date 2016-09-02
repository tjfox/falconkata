#include "romanNumeralCalculator.h"
#include <ctype.h>
#include <string.h>

static const char* validTokens[] = {"I", "V"};
static int tokenValues[] = {1, 5};

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

int roman_numeral_to_int(const char* operand)
{
  if(!strcmp(operand, "I"))
  {
    return 1;
  }
  else if(!strcmp(operand, "V"))
  {
    return 5;
  }
}

void int_to_roman_numeral(int value, char* destination)
{
  strcpy(destination, "");
  int lastIndex = sizeof(tokenValues) / sizeof(tokenValues[0]) - 1;
  while( value != 0 )
  {
    if( value >= tokenValues[lastIndex] )
    {
      strcat(destination, validTokens[lastIndex]);
      value -= tokenValues[lastIndex];
    }
    else
    {
      --lastIndex;
    }
  }
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

    int op1Int = roman_numeral_to_int(operand1);
    int op2Int = roman_numeral_to_int(operand2);

    int addedValue = op1Int + op2Int;

    int_to_roman_numeral(addedValue, result);
    return OK;
  }
