#include "romanNumeralCalculator.h"
#include <ctype.h>
#include <string.h>

static const char* validTokens[] = {"I", "IV", "V"};
static int tokenValues[] = {1, 4, 5};

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
  int lastIndex = sizeof(validTokens) / sizeof(validTokens[0]) - 1;
  int value = 0;

  while( *operand != '\0' && lastIndex >= 0 )
  {
    const char * match = strstr(operand, validTokens[lastIndex]);
    if( match == operand )
    {
      value += tokenValues[lastIndex];
      operand += strlen(validTokens[lastIndex]);
    }
    else
    {
      --lastIndex;
    }
  }

  return value;
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

    if( op1Int == 0 || op2Int == 0 )
    {
      return INVALID_PARAM;
    }

    int addedValue = op1Int + op2Int;

    int_to_roman_numeral(addedValue, result);
    return OK;
  }
