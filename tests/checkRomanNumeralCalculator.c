#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeralCalculator.h"

START_TEST(test_I_plus_I_equals_II)
{
  const char* operand1 = "I";
  char result[10];

  add_roman_numeral(operand1, operand1, result);

  ck_assert_str_eq(result, "II");
}
END_TEST

START_TEST(test_II_plus_I_equals_III)
{
  const char* operand1 = "II";
  const char* operand2 = "I";

  char result[10];

  add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "III");
}
END_TEST


START_TEST(test_IV_plus_I_equals_V)
{
  const char* operand1 = "IV";
  const char* operand2 = "I";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "V");
}
END_TEST

START_TEST(test_V_plus_I_equals_VI)
{
  const char* operand1 = "V";
  const char* operand2 = "I";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "VI");
}
END_TEST

START_TEST(test_successful_add_returns_OK)
{
  const char * operand1 = "I";
  char result[10];

  int success = add_roman_numeral(operand1, operand1, result);

  ck_assert_int_eq(success, OK);
}
END_TEST

START_TEST(test_add_lower_case_operand_returns_INVALID_PARAM)
{
  const char * operand1 = "I";
  const char * operand2 = "i";
  char result[10];

  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_int_eq(success, INVALID_PARAM);
}
END_TEST

START_TEST(test_add_invalid_numeral_returns_INVALID_PARAM)
{
  const char * operand1 = "I";
  const char * operand2 = "S";
  char result[10];

  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_int_eq(success, INVALID_PARAM);
}
END_TEST

START_TEST(test_invalid_numeral_ordering_returns_INVALID_PARAM)
{
  const char * operand1 = "IIIV";
  const char * operand2 = "I";
  char result[10];

  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_int_eq(success, INVALID_PARAM);
}
END_TEST

START_TEST(test_add_IIII_returns_INVALID_PARAM)
{
  const char * operand1 = "IIII";
  const char * operand2 = "I";
  char result[10];

  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_int_eq(success, INVALID_PARAM);
}
END_TEST

Suite * calculator_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Calculator");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_I_plus_I_equals_II);
  tcase_add_test(tc_core, test_II_plus_I_equals_III);
  tcase_add_test(tc_core, test_IV_plus_I_equals_V);
  tcase_add_test(tc_core, test_V_plus_I_equals_VI);
  tcase_add_test(tc_core, test_successful_add_returns_OK);
  tcase_add_test(tc_core, test_add_lower_case_operand_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_add_invalid_numeral_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_invalid_numeral_ordering_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_add_IIII_returns_INVALID_PARAM);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = calculator_suite();
    sr = srunner_create(s);
    // srunner_set_fork_status (sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
