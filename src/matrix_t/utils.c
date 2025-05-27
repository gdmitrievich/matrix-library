#include "utils.h"

#include "matrix_t.h"

int s21_is_valid_matrix(const matrix_t* matrix) {
  return matrix && matrix->matrix &&
         s21_is_matrix_rows_and_columns_valid(matrix->rows, matrix->columns);
}

int s21_is_matrix_rows_and_columns_valid(int rows, int columns) {
  return !(rows == 0 && columns == 0) && rows >= 0 && columns >= 0;
}
