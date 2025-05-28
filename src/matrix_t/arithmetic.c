#include "matrix_t/arithmetic.h"

#include "matrix_operation_status_code_t.h"
#include "matrix_t.h"
#include "matrix_t/utils.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !s21_is_matrix_valid(B) || !result) {
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

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !s21_is_matrix_valid(B) || !result) {
    return INVALID_MATRIX;
  } else if (!s21_are_orders_of_matrixes_equal(A, B)) {
    return COMPUTATION_ERROR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !result) {
    return INVALID_MATRIX;
  }

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !s21_is_matrix_valid(B) || !result) {
    return INVALID_MATRIX;
  } else if (!s21_can_mult_matrices_with_their_orders(A, B)) {
    return COMPUTATION_ERROR;
  }

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < B->columns; ++j) {
      double sum = 0;
      for (int k = 0; k < B->rows; ++k) {
        sum += A->matrix[i][k] * B->matrix[k][j];
      }
      result->matrix[i][j] = sum;
    }
  }

  return OK;
}

int s21_can_mult_matrices_with_their_orders(const matrix_t *first,
                                            const matrix_t *second) {
  return first->columns == second->rows;
}