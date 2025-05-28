#ifndef MATRIX_T_UTILS_H
#define MATRIX_T_UTILS_H

#include "matrix_t.h"

int s21_is_valid_matrix(const matrix_t *matrix);

int s21_is_matrix_rows_and_columns_valid(int rows, int columns);

int s21_are_orders_of_matrixes_equal(const matrix_t *first,
                                     const matrix_t *second);

#endif  // MATRIX_T_UTILS_H