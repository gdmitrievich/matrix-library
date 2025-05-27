#ifndef MATRIX_OPERATION_STATUS_CODE_T_H
#define MATRIX_OPERATION_STATUS_CODE_T_H

typedef enum {
  OK = 0,
  INVALID_MATRIX = 1,
  COMPUTATION_ERROR = 2
} matrix_operation_status_code_t;

#endif  // MATRIX_OPERATION_STATUS_CODE_T_H