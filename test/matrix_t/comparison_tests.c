#include <check.h>
#include <stdlib.h>  // For exit status.

#include "../src/matrix_t.h"
#include "../src/matrix_t/comparison.h"
#include "../src/matrix_t/matrix_operation_status_code_t.h"
#include "matrix_t/matrix_t_test_helpers.h"

START_TEST(em_left_matrix_is_null_returns_0) {
  int status_code = s21_eq_matrix(NULL, &TEMPORARY_EMPTY_MATRIX_T);

  ck_assert_int_eq(FAILURE, status_code);
}
END_TEST

START_TEST(em_right_matrix_is_null_returns_0) {
  int status_code = s21_eq_matrix(&TEMPORARY_EMPTY_MATRIX_T, NULL);

  ck_assert_int_eq(FAILURE, status_code);
}
END_TEST

START_TEST(em_matrix_matrixes_is_null_returns_0) {
  int status_code =
      s21_eq_matrix(&TEMPORARY_EMPTY_MATRIX_T, &TEMPORARY_EMPTY_MATRIX_T);

  ck_assert_int_eq(FAILURE, status_code);
}
END_TEST

START_TEST(em_rows_and_cols_eq_zero_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &left_matrix);
  left_matrix.columns = 0;
  left_matrix.rows = 0;
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_rows_is_negative_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &left_matrix);
  left_matrix.rows = -1;
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_columns_is_negative_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &left_matrix);
  left_matrix.columns = -1;
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_left_rows_ne_right_rows_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "5 5 5 5", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_left_columsn_ne_right_columns_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 3, "5 5 5", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(1, 2, "5 5", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_left_elements_ne_right_elements_1_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "1 2 3 4 5 6", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 3, "1.1 2.1 3 4 5 6.12", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_left_elements_ne_right_elements_2_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "1 2 3 4 5 6", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(3, 2, "1.1 2.1 3 4 5 6.12", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_matrixes_equals_with_max_precision_returns_1) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.1234567", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.1234567", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(SUCCESS, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_matrixes_ne_with_premax_precision_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.123456", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.123457", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_matrixes_ne_with_max_precision_returns_0) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.1234567", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.1234568", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(FAILURE, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

START_TEST(em_matrixes_equal_with_precision_but_not_actual_returns_1) {
  matrix_t left_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.12345678", &left_matrix);
  matrix_t right_matrix = EMPTY_MATRIX_T;
  s21_init_matrix(2, 2, "1 2 3 4.12345679", &right_matrix);

  int status_code = s21_eq_matrix(&left_matrix, &right_matrix);

  ck_assert_int_eq(SUCCESS, status_code);

  s21_remove_matrix(&left_matrix);
  s21_remove_matrix(&right_matrix);
}
END_TEST

Suite* comparison_suite() {
  Suite* s_c = suite_create("Comparison");

  TCase* tc_em = tcase_create("s21_eq_matrix");
  tcase_add_test(tc_em, em_left_matrix_is_null_returns_0);
  tcase_add_test(tc_em, em_right_matrix_is_null_returns_0);
  tcase_add_test(tc_em, em_matrix_matrixes_is_null_returns_0);
  tcase_add_test(tc_em, em_rows_and_cols_eq_zero_returns_0);
  tcase_add_test(tc_em, em_rows_is_negative_returns_0);
  tcase_add_test(tc_em, em_columns_is_negative_returns_0);
  tcase_add_test(tc_em, em_left_rows_ne_right_rows_returns_0);
  tcase_add_test(tc_em, em_left_columsn_ne_right_columns_returns_0);
  tcase_add_test(tc_em, em_left_elements_ne_right_elements_1_returns_0);
  tcase_add_test(tc_em, em_left_elements_ne_right_elements_2_returns_0);
  tcase_add_test(tc_em, em_matrixes_equals_with_max_precision_returns_1);
  tcase_add_test(tc_em, em_matrixes_ne_with_premax_precision_returns_0);
  tcase_add_test(tc_em, em_matrixes_ne_with_max_precision_returns_0);
  tcase_add_test(tc_em,
                 em_matrixes_equal_with_precision_but_not_actual_returns_1);
  suite_add_tcase(s_c, tc_em);

  return s_c;
}

int main(void) {
  int n_failed = 0;
  SRunner* sr = srunner_create(comparison_suite());

  srunner_run_all(sr, CK_NORMAL);
  n_failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return n_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
