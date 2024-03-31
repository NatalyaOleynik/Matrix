#include "matrix.h"

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  resulting_code res = OK;
  if (is_matrix(A) && is_matrix(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      res = create_matrix(A->rows, A->columns, result);
      if (!res) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      }
    } else
      res = CALCULATION_ERROR;
  } else
    res = INCORRECT_MATRIX;
  return res;
}