#include "matrix_t.h"

#include <stddef.h>

#include "common.h"
#include "matrix_t/matrix_operation_status_code_t.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (!s21_is_matrix_params_valid(rows, columns, result)) {
    return INVALID_MATRIX;
  }

  matrix_operation_status_code_t status_code = OK;
  result->matrix =
      s21_safe_malloc((size_t)rows * sizeof(double*) +
                      (size_t)rows * (size_t)columns * sizeof(double));
  if (result->matrix != NULL) {
    double* ptr = (double*)(result->matrix + rows);
    for (int i = 0; i < rows; ++i) {
      result->matrix[i] = ptr + columns * i;
    }
    result->rows = rows;
    result->columns = columns;
  } else {
    status_code = INVALID_MATRIX;
  }

  return status_code;
}

int s21_is_matrix_params_valid(int rows, int columns, const matrix_t* matrix) {
  return !(rows == 0 && columns == 0) && rows >= 0 && columns >= 0 &&
         matrix != NULL;
}