#ifndef MATRIX_T_ARITHMETIC_H
#define MATRIX_T_ARITHMETIC_H

#include "matrix_t.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_can_mult_matrices_with_their_orders(const matrix_t *first,
                                            const matrix_t *second);

#endif  // MATRIX_T_ARITHMETIC_H