#include "matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  resulting_code res = OK;
  if (is_matrix(A) && is_matrix(B)) {
    if (A->columns == B->rows) {
      res = create_matrix(A->rows, B->columns, result);
      if (!res) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++)
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else
      res = CALCULATION_ERROR;
  } else
    res = INCORRECT_MATRIX;
  return res;
}