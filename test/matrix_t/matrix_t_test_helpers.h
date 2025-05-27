#ifndef MATRIX_T_TEST_HELPERS_H
#define MATRIX_T_TEST_HELPERS_H

#include "../src/matrix_t.h"
#include "../src/matrix_t/matrix_operation_status_code_t.h"

/// @brief Initializes 'matrix' of 'rows' x 'cols' size with given double
/// elements from 'elements' string. The number of elements must always match
/// the size of the 'matrix', otherwise 'matrix' will be filled by zeroes. In
/// case of error, 'matrix' will be emptied.
/// @param elements Sequence of double elements separated by space.
/// @return OK or INVALID_MATRIX if invalid args were given or the number of
/// elements in 'elements' string doesn't match the size of the 'matrix'.
matrix_operation_status_code_t s21_init_matrix(int rows, int columns,
                                               const char *elements,
                                               matrix_t *matrix);

matrix_operation_status_code_t s21_parse_elements_to_array_of_doubles(
    int rows, int columns, const char *elements, double *elements_array);

void s21_copy_array_of_doubles_to_matrix(int rows, int columns,
                                         const double *elements_array,
                                         matrix_t *matrix);

void s21_ck_assert_matrix_eq(const matrix_t *expected, const matrix_t *actual);

int s21_two_doubles_equals_with_tolerance(double first, double second,
                                          double epsilon);

void s21_print_matrix_with_message(const char *message, const matrix_t *matrix);

#endif  // MATRIX_T_TEST_HELPERS_H