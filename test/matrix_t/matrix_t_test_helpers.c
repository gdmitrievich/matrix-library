#include "matrix_t/matrix_t_test_helpers.h"

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/common.h"
#include "../src/matrix_t.h"
#include "../src/matrix_t/comparison.h"
#include "../src/matrix_t/matrix_operation_status_code_t.h"

matrix_operation_status_code_t s21_init_matrix(int rows, int columns,
                                               const char *elements,
                                               matrix_t *matrix) {
  matrix_operation_status_code_t status_code = OK;
  status_code = (elements != NULL ? OK : INVALID_MATRIX);
  if (status_code == OK) status_code = s21_create_matrix(rows, columns, matrix);
  if (status_code == OK) {
    double *elements_array =
        s21_safe_malloc((size_t)rows * columns * sizeof(double));
    if (elements_array) {
      status_code = s21_parse_elements_to_array_of_doubles(
          rows, columns, elements, elements_array);
      if (status_code == OK) {
        s21_copy_array_of_doubles_to_matrix(rows, columns, elements_array,
                                            matrix);
      }
      free(elements_array);
    } else {
      status_code = INVALID_MATRIX;
    }
  } else if (matrix) {
    *matrix = TEMPORARY_EMPTY_MATRIX_T;
  }

  return status_code;
}

matrix_operation_status_code_t s21_parse_elements_to_array_of_doubles(
    int rows, int columns, const char *elements, double *elements_array) {
  int idx = 0;
  char *token = NULL;
  char *elements_copy = s21_safe_malloc(strlen(elements) + 1);
  if (elements_copy) {
    memcpy(elements_copy, elements, strlen(elements) + 1);
    token = strtok(elements_copy, " ");
    while (token != NULL && idx < rows * columns) {
      elements_array[idx++] = strtod(token, NULL);
      token = strtok(NULL, " ");
    }

    free(elements_copy);
  }

  return (idx == rows * columns && token == NULL) ? OK : INVALID_MATRIX;
}

void s21_copy_array_of_doubles_to_matrix(int rows, int columns,
                                         const double *elements_array,
                                         matrix_t *matrix) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      matrix->matrix[i][j] = elements_array[i * columns + j];
    }
  }
}

void s21_ck_assert_matrix_eq(const matrix_t *expected, const matrix_t *actual) {
  ck_assert_int_eq(expected->rows, actual->rows);
  ck_assert_int_eq(expected->columns, actual->columns);

  for (int i = 0; i < expected->rows; ++i) {
    for (int j = 0; j < expected->columns; ++j) {
      if (!s21_are_doubles_equal_with_precision(expected->matrix[i][j],
                                                actual->matrix[i][j],
                                                COMPARISON_PRECISION)) {
        s21_print_matrix_with_message("Expected matrix: ", expected);
        s21_print_matrix_with_message("Actual matrix: ", actual);
      }
      ck_assert_double_eq_tol(expected->matrix[i][j], actual->matrix[i][j],
                              COMPARISON_PRECISION);
    }
  }
}

void s21_print_matrix_with_message(const char *message,
                                   const matrix_t *matrix) {
  printf("%s\n", message);
  printf("[%dx%d]\n", matrix->rows, matrix->columns);
  s21_print_matrix(matrix);
}

void s21_print_matrix(const matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      printf("%f ", matrix->matrix[i][j]);
      if (j + 1 == matrix->columns) {
        printf("\n");
      }
    }
  }
}