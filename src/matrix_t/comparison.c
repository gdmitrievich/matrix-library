#include "comparison.h"

#include <math.h>

#include "matrix_t/utils.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) ||
      !s21_are_orders_of_matrixes_equal(A, B)) {
    return FAILURE;
  }

  int status_code = SUCCESS;
  for (int i = 0; status_code == SUCCESS && i < A->rows; ++i) {
    for (int j = 0; status_code == SUCCESS && j < A->columns; ++j) {
      if (!s21_are_doubles_equal_with_precision(
              A->matrix[i][j], B->matrix[i][j], COMPARISON_PRECISION)) {
        status_code = FAILURE;
      }
    }
  }

  return status_code;
}

int s21_are_doubles_equal_with_precision(double first, double second,
                                         double precision) {
  return fabs(first - second) <= precision;
}
