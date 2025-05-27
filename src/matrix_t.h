#ifndef MATRIX_T_H
#define MATRIX_T_H

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

#include <stddef.h>
#define EMPTY_MATRIX_T \
  { NULL, 0, 0 }
#define TEMPORARY_EMPTY_MATRIX_T (matrix_t) EMPTY_MATRIX_T

int s21_create_matrix(int rows, int columns, matrix_t* result);

int s21_is_matrix_params_valid(int rows, int columns, const matrix_t* matrix);

#endif  // MATRIX_T_H