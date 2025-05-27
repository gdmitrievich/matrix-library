#include "matrix_t/matrix_t_test_helpers.h"

#include <stdlib.h>

#include "../src/common.h"
#include "../src/matrix_t.h"
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
