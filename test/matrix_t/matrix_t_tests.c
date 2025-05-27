#include <check.h>
#include <limits.h>
#include <stdlib.h>  // For exit status.

#include "../src/matrix_t.h"
#include "../src/matrix_t/matrix_operation_status_code_t.h"
#include "matrix_t/matrix_t_test_helpers.h"

START_TEST(cm_rows_and_cols_eq_zero_returns_1) {
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code = s21_create_matrix(0, 0, &actual_matrix);

  ck_assert_int_eq(INVALID_MATRIX, status_code);
}
END_TEST

START_TEST(cm_rows_is_negative_returns_1) {
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code = s21_create_matrix(-1, 5, &actual_matrix);

  ck_assert_int_eq(INVALID_MATRIX, status_code);
}
END_TEST

START_TEST(cm_columns_is_negative_returns_1) {
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code = s21_create_matrix(5, -1, &actual_matrix);

  ck_assert_int_eq(INVALID_MATRIX, status_code);
}
END_TEST

START_TEST(cm_result_is_null_returns_1) {
  int status_code = s21_create_matrix(5, 5, NULL);

  ck_assert_int_eq(INVALID_MATRIX, status_code);
}
END_TEST

START_TEST(cm_1by1_square_matrix_returns_0) {
  matrix_t expected_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "0", &expected_matrix);
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code = s21_create_matrix(1, 1, &actual_matrix);

  s21_ck_assert_matrix_eq(&expected_matrix, &actual_matrix);
  ck_assert_int_eq(OK, status_code);

  free(expected_matrix.matrix);
  free(actual_matrix.matrix);
}
END_TEST

START_TEST(cm_2by2_square_matrix_returns_0) {
  matrix_t expected_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "0 0 0 0", &expected_matrix);
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code = s21_create_matrix(2, 2, &actual_matrix);

  s21_ck_assert_matrix_eq(&expected_matrix, &actual_matrix);
  ck_assert_int_eq(OK, status_code);

  free(expected_matrix.matrix);
  free(actual_matrix.matrix);
}
END_TEST

START_TEST(cm_3by3_square_matrix_returns_0) {
  matrix_t expected_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(3, 3, "0 0 0 0 0 0 0 0 0", &expected_matrix);
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code = s21_create_matrix(3, 3, &actual_matrix);

  s21_ck_assert_matrix_eq(&expected_matrix, &actual_matrix);
  ck_assert_int_eq(OK, status_code);

  free(expected_matrix.matrix);
  free(actual_matrix.matrix);
}
END_TEST

START_TEST(cm_matrix_is_too_big_returns_1) {
  matrix_t actual_matrix = EMPTY_MATRIX_T;

  int status_code =
      s21_create_matrix(INT32_MAX / 2, INT32_MAX / 2, &actual_matrix);

  ck_assert_int_eq(INVALID_MATRIX, status_code);
}
END_TEST

START_TEST(rm_matrix_is_null) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(rm_1by1_square_matrix) {
  matrix_t expected_matrix = EMPTY_MATRIX_T;
  matrix_t actual_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "5.5", &actual_matrix);

  s21_remove_matrix(&actual_matrix);

  s21_ck_assert_matrix_eq(&expected_matrix, &actual_matrix);
}
END_TEST

START_TEST(rm_2by4_matrix) {
  matrix_t expected_matrix = EMPTY_MATRIX_T;
  matrix_t actual_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 4, "1 2 3 4 5 6 7 8", &actual_matrix);

  s21_remove_matrix(&actual_matrix);

  s21_ck_assert_matrix_eq(&expected_matrix, &actual_matrix);
}
END_TEST

Suite *base_suite(void) {
  Suite *s_b = suite_create("Base");

  TCase *tc_cm = tcase_create("s21_create_matrix");
  tcase_add_test(tc_cm, cm_rows_and_cols_eq_zero_returns_1);
  tcase_add_test(tc_cm, cm_rows_is_negative_returns_1);
  tcase_add_test(tc_cm, cm_columns_is_negative_returns_1);
  tcase_add_test(tc_cm, cm_result_is_null_returns_1);
  tcase_add_test(tc_cm, cm_1by1_square_matrix_returns_0);
  tcase_add_test(tc_cm, cm_2by2_square_matrix_returns_0);
  tcase_add_test(tc_cm, cm_3by3_square_matrix_returns_0);
  tcase_add_test(tc_cm, cm_matrix_is_too_big_returns_1);
  suite_add_tcase(s_b, tc_cm);

  TCase *tc_rm = tcase_create("s21_remove_matrix");
  tcase_add_test(tc_rm, rm_matrix_is_null);
  tcase_add_test(tc_rm, rm_1by1_square_matrix);
  tcase_add_test(tc_rm, rm_2by4_matrix);
  suite_add_tcase(s_b, tc_rm);

  return s_b;
}

int main(void) {
  int n_failed = 0;
  SRunner *sr = srunner_create(base_suite());

  srunner_run_all(sr, CK_NORMAL);
  n_failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return n_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
