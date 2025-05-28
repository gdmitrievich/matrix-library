#ifndef MATRIX_T_MATH_H
#define MATRIX_T_MATH_H

#include "matrix_t.h"

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_calc_complement(int row, int column, const matrix_t *matrix,
                        double *complement);

#endif  // MATRIX_T_MATH_H