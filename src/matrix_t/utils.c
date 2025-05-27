#include "utils.h"

#include "matrix_t.h"

int s21_is_matrix_params_valid(int rows, int columns, const matrix_t* matrix) {
  return !(rows == 0 && columns == 0) && rows >= 0 && columns >= 0 && matrix;
}