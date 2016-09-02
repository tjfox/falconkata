#include "romanNumeralCalculator.h"
#include <ctype.h>
#include <string.h>

static const int MAX_VALUE = 3999;

typedef struct numeral numeral;
struct numeral
{
  const char* token;
  int numeralValue;
  int maxNumToken;
};

static const numeral VALID_TOKENS[] = {
  {.token = "M",  .numeralValue = 1000, .maxNumToken = 3},
  {.token = "D",  .numeralValue = 500,  .maxNumToken = 1},
  {.token = "C",  .numeralValue = 100,  .maxNumToken = 3},
  {.token = "L",  .numeralValue = 50,   .maxNumToken = 1},
  {.token = "X",  .numeralValue = 10,   .maxNumToken = 3},
  {.token = "V",  .numeralValue = 5,    .maxNumToken = 1},
  {.token = "IV", .numeralValue = 4,    .maxNumToken = 1},
  {.token = "I",  .numeralValue = 1,    .maxNumToken = 3}
};

static const int NUM_TOKENS = sizeof(VALID_TOKENS) / sizeof(VALID_TOKENS[0]);

int roman_numeral_to_int(const char* operand)
{
  int tokenIndex = 0;
  int value = 0;
  int count = 0;
  while( *operand != '\0' && tokenIndex < NUM_TOKENS )
  {
    const char * match = strstr(operand, VALID_TOKENS[tokenIndex].token);
    if( match == operand )
    {
      if( ++count > VALID_TOKENS[tokenIndex].maxNumToken ) //We encountered an invalid numeral and can't continue
      {
        break;
      }
      value += VALID_TOKENS[tokenIndex].numeralValue;
      operand += strlen(VALID_TOKENS[tokenIndex].token);
    }
    else
    {
      count = 0;
      ++tokenIndex;
    }
  }

  if( *operand != '\0' )
  {
    value = 0;
  }

  return value;
}

void int_to_roman_numeral(int value, char* destination)
{
  strcpy(destination, "");
  int tokenIndex = 0;
  while( value != 0 )
  {
    if( value >= VALID_TOKENS[tokenIndex].numeralValue )
    {
      strcat(destination, VALID_TOKENS[tokenIndex].token);
      value -= VALID_TOKENS[tokenIndex].numeralValue;
    }
    else
    {
      ++tokenIndex;
    }
  }
}

int add_roman_numeral(const char* operand1,
  const char* operand2, char* result)
{
  int op1Int = roman_numeral_to_int(operand1);
  int op2Int = roman_numeral_to_int(operand2);

  if( op1Int == 0 || op2Int == 0 )
  {
    return INVALID_PARAM;
  }

  int addedValue = op1Int + op2Int;

  if( addedValue > MAX_VALUE )
  {
    return INVALID_RESULT;
  }
  int_to_roman_numeral(addedValue, result);
  return OK;
}

int sub_roman_numeral(const char* operand1,
    const char* operand2, char* result)
{
  int op1Int = roman_numeral_to_int(operand1);
  int op2Int = roman_numeral_to_int(operand2);

  if( op1Int - op2Int <= 0 )
  {
    return INVALID_RESULT;
  }

  return OK;
}
