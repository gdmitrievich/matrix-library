#include "math.h"

#include "matrix_operation_status_code_t.h"
#include "matrix_t.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !result) {
    return INVALID_MATRIX;
  }

  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !result) {
    return INVALID_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    return COMPUTATION_ERROR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      double complement = 0;
      s21_calc_complement(i, j, A, &complement);
      result->matrix[i][j] = complement;
    }
  }

  return OK;
}
