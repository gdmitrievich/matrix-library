#include <check.h>
#include <stdlib.h>  // For exit status.

#include "../src/matrix_t.h"
#include "../src/matrix_t/math.h"
#include "../src/matrix_t/matrix_operation_status_code_t.h"
#include "matrix_t/matrix_t_test_helpers.h"

START_TEST(t_A_is_null_returns_1) {
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_transpose(NULL, &actual_result);

  ck_assert_int_eq(INVALID_MATRIX, status_code);
}
END_TEST

START_TEST(t_result_matrix_is_null_returns_1) {
  matrix_t matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &matrix);

  int status_code = s21_transpose(&matrix, NULL);

  ck_assert_int_eq(INVALID_MATRIX, status_code);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(t_1by1_returns_0) {
  matrix_t matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "5.5", &matrix);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "5.5", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_transpose(&matrix, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(t_3by3_returns_0) {
  matrix_t matrix = EMPTY_MATRIX_T;
  s21_init_matrix(3, 3, "1 2 3 4 5 6 7 8 9", &matrix);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(3, 3, "1 4 7 2 5 8 3 6 9", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_transpose(&matrix, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(t_2by3_returns_0) {
  matrix_t matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "1 2 3 4 5 6", &matrix);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "1 4 2 5 3 6", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_transpose(&matrix, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(t_3by2_returns_0) {
  matrix_t matrix = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "1 4 2 5 3 6", &matrix);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "1 2 3 4 5 6", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_transpose(&matrix, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

Suite* math_suite() {
  Suite* s_m = suite_create("Math");

  TCase* tc_em = tcase_create("s21_transpose");
  tcase_add_test(tc_em, t_A_is_null_returns_1);
  tcase_add_test(tc_em, t_result_matrix_is_null_returns_1);
  tcase_add_test(tc_em, t_1by1_returns_0);
  tcase_add_test(tc_em, t_3by3_returns_0);
  tcase_add_test(tc_em, t_2by3_returns_0);
  tcase_add_test(tc_em, t_3by2_returns_0);
  suite_add_tcase(s_m, tc_em);

  return s_m;
}

int main(void) {
  int n_failed = 0;
  SRunner* sr = srunner_create(math_suite());

  srunner_run_all(sr, CK_NORMAL);
  n_failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return n_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
