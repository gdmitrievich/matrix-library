#ifndef MATRIX_T_COMPARISON_H
#define MATRIX_T_COMPARISON_H

#include "matrix_t.h"

#define SUCCESS 1
#define FAILURE 0

#define COMPARISON_PRECISION 0.00000001

int s21_eq_matrix(matrix_t *A, matrix_t *B);

#endif  // MATRIX_T_COMPARISON_H