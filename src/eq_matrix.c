#include "matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (is_matrix(A) && is_matrix(B) && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if ((fabs(A->matrix[i][j] - B->matrix[i][j])) >= 1e-7) {
          res = FAILURE;
          break;
        }
      }
    }
  } else
    res = FAILURE;
  return res;
}