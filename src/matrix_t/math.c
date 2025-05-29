#include "math.h"

#include <math.h>

#include "matrix_operation_status_code_t.h"
#include "matrix_t.h"
#include "matrix_t/utils.h"

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

int s21_calc_complement(int row, int column, const matrix_t *matrix,
                        double *complement) {
  if (!s21_is_matrix_valid(matrix)) {
    return INVALID_MATRIX;
  } else if (!s21_is_square_matrix(matrix)) {
    return COMPUTATION_ERROR;
  }

  double minor = 0;
  s21_calc_minor(row, column, matrix, &minor);
  *complement = pow(-1, row + 1 + column + 1) * minor;

  return OK;
}

int s21_calc_minor(int row, int column, const matrix_t *matrix, double *minor) {
  if (!s21_is_matrix_valid(matrix)) {
    return INVALID_MATRIX;
  } else if (!s21_is_square_matrix(matrix)) {
    return COMPUTATION_ERROR;
  }

  if (matrix->rows == 1) {
    *minor = matrix->matrix[0][0];
  } else {
    matrix_t cropped_matrix = EMPTY_MATRIX_T;
    s21_crop_matrix_by_one_order(row, column, matrix, &cropped_matrix);
    s21_determinant(&cropped_matrix, minor);
    s21_remove_matrix(&cropped_matrix);
  }

  return OK;
}

void s21_crop_matrix_by_one_order(int row, int column, const matrix_t *matrix,
                                  matrix_t *result) {
  s21_create_matrix(matrix->rows - 1, matrix->columns - 1, result);
  for (int i = 0, k = 0; i < matrix->rows; ++i) {
    if (i != row) {
      for (int j = 0, l = 0; j < matrix->columns; ++j) {
        if (j != column) result->matrix[k][l++] = matrix->matrix[i][j];
      }
      ++k;
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_is_matrix_valid(A) || !result) {
    return INVALID_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    return COMPUTATION_ERROR;
  }

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = 0;
    for (int i = 0; i < A->columns; ++i) {
      double complement = 0;
      s21_calc_complement(0, i, A, &complement);
      *result += A->matrix[0][i] * complement;
    }
  }

  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_is_matrix_valid(A) || !result) {
    return INVALID_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    return COMPUTATION_ERROR;
  }

  matrix_operation_status_code_t status_code = OK;
  double determinant = 0;
  s21_determinant(A, &determinant);
  if (determinant != 0) {
    if (A->rows != 1) {
      matrix_t complement_matrix = EMPTY_MATRIX_T;
      s21_calc_complements(A, &complement_matrix);
      matrix_t transpose_matrix = EMPTY_MATRIX_T;
      s21_transpose(&complement_matrix, &transpose_matrix);
      s21_mult_number(&transpose_matrix, 1 / determinant, result);

      s21_remove_matrix(&complement_matrix);
      s21_remove_matrix(&transpose_matrix);
    } else {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
    }

  } else {
    status_code = COMPUTATION_ERROR;
  }

  return status_code;
}