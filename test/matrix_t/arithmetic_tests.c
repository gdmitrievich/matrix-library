#include <check.h>
#include <stdlib.h>  // For exit status.

#include "../src/matrix_t.h"
#include "../src/matrix_t/arithmetic.h"
#include "../src/matrix_t/matrix_operation_status_code_t.h"
#include "matrix_t/matrix_t_test_helpers.h"

START_TEST(sm_A_is_null_returns_1) {
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &second);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(NULL, &second, &actual_result);

  ck_assert_int_eq(INVALID_MATRIX, status_code);

  s21_remove_matrix(&second);
}
END_TEST

START_TEST(sm_B_is_null_returns_1) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &first);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, NULL, &actual_result);

  ck_assert_int_eq(INVALID_MATRIX, status_code);

  s21_remove_matrix(&first);
}
END_TEST

START_TEST(sm_result_matrix_is_null_returns_1) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &second);

  int status_code = s21_sum_matrix(&first, &second, NULL);

  ck_assert_int_eq(INVALID_MATRIX, status_code);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(sm_1by1_returns_0) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "5.5", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "5.5", &second);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(1, 1, "11", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, &second, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(sm_3by3_returns_0) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(3, 3, "1 2 3 4 5 6 7 8 9", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(3, 3, "9 8 7 6 5 4 3 2 1", &second);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(3, 3, "10 10 10 10 10 10 10 10 10", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, &second, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(sm_2by3_returns_0) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "1 2 3 4 5 6", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "9 8 7 6 5 4", &second);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "10 10 10 10 10 10", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, &second, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(sm_3by2_returns_0) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "1 2 3 4 5 6", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "9 8 7 6 5 4", &second);
  matrix_t expected_result = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "10 10 10 10 10 10", &expected_result);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, &second, &actual_result);

  ck_assert_int_eq(OK, status_code);
  s21_ck_assert_matrix_eq(&expected_result, &actual_result);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(sm_3by2_with_2by3_returns_2) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "1 2 3 4 5 6", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "9 8 7 6 5 4", &second);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, &second, &actual_result);

  ck_assert_int_eq(COMPUTATION_ERROR, status_code);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

START_TEST(sm_1by3_with_1by2_returns_2) {
  matrix_t first = EMPTY_MATRIX_T;
  s21_init_matrix(1, 3, "1 2 3", &first);
  matrix_t second = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "9 8", &second);
  matrix_t actual_result = EMPTY_MATRIX_T;

  int status_code = s21_sum_matrix(&first, &second, &actual_result);

  ck_assert_int_eq(COMPUTATION_ERROR, status_code);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
}
END_TEST

Suite* arithmetic_suite() {
  Suite* s_a = suite_create("Arithmetic");

  TCase* tc_sm = tcase_create("s21_sum_matrix");
  tcase_add_test(tc_sm, sm_A_is_null_returns_1);
  tcase_add_test(tc_sm, sm_B_is_null_returns_1);
  tcase_add_test(tc_sm, sm_result_matrix_is_null_returns_1);
  tcase_add_test(tc_sm, sm_1by1_returns_0);
  tcase_add_test(tc_sm, sm_3by3_returns_0);
  tcase_add_test(tc_sm, sm_2by3_returns_0);
  tcase_add_test(tc_sm, sm_3by2_returns_0);
  tcase_add_test(tc_sm, sm_3by2_with_2by3_returns_2);
  tcase_add_test(tc_sm, sm_1by3_with_1by2_returns_2);
  suite_add_tcase(s_a, tc_sm);

  return s_a;
}

int main(void) {
  int n_failed = 0;
  SRunner* sr = srunner_create(arithmetic_suite());

  srunner_run_all(sr, CK_NORMAL);
  n_failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return n_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
