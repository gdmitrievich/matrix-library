#ifndef MATRIX_T_UTILS_H
#define MATRIX_T_UTILS_H

#include "matrix_t.h"

int s21_is_matrix_valid(const matrix_t *matrix);

int s21_is_matrix_rows_and_columns_valid(int rows, int columns);

int s21_are_orders_of_matrixes_equal(const matrix_t *first,
                                     const matrix_t *second);

int s21_is_square_matrix(const matrix_t *matrix);

#endif  // MATRIX_T_UTILS_H