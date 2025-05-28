#include "matrix_t/arithmetic.h"

#include "matrix_operation_status_code_t.h"
#include "matrix_t.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) || !result) {
    return INVALID_MATRIX;
  } else if (!s21_are_orders_of_matrixes_equal(A, B)) {
    return COMPUTATION_ERROR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}
