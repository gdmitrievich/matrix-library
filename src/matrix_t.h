#ifndef MATRIX_T_H
#define MATRIX_T_H

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

#endif  // MATRIX_T_H