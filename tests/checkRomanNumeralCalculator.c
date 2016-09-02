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

START_TEST(test_X_plus_I_equals_XI)
{
  const char* operand1 = "X";
  const char* operand2 = "I";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "XI");
}
END_TEST

START_TEST(test_X_plus_L_equals_LX)
{
  const char* operand1 = "X";
  const char* operand2 = "L";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "LX");
}
END_TEST

START_TEST(test_L_plus_C_equals_CL)
{
  const char* operand1 = "L";
  const char* operand2 = "C";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "CL");
}
END_TEST

START_TEST(test_C_plus_D_equals_DC)
{
  const char* operand1 = "C";
  const char* operand2 = "D";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "DC");
}
END_TEST

START_TEST(test_D_plus_M_equals_MD)
{
  const char* operand1 = "D";
  const char* operand2 = "M";
  char result[10];
  int success = add_roman_numeral(operand1, operand2, result);

  ck_assert_str_eq(result, "MD");
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

START_TEST(test_add_VV_returns_INVALID_PARAM)
{
  const char * operand1 = "VV";
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
  tcase_add_test(tc_core, test_X_plus_I_equals_XI);
  tcase_add_test(tc_core, test_X_plus_L_equals_LX);
  tcase_add_test(tc_core, test_L_plus_C_equals_CL);
  tcase_add_test(tc_core, test_C_plus_D_equals_DC);
  tcase_add_test(tc_core, test_D_plus_M_equals_MD);
  tcase_add_test(tc_core, test_successful_add_returns_OK);
  tcase_add_test(tc_core, test_add_lower_case_operand_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_add_invalid_numeral_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_invalid_numeral_ordering_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_add_IIII_returns_INVALID_PARAM);
  tcase_add_test(tc_core, test_add_VV_returns_INVALID_PARAM);
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
