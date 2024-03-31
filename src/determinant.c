#include "matrix.h"

int determinant(matrix_t *A, double *result) {
  *result = 0.0;
  resulting_code res = OK;
  if (is_matrix(A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else if (A->rows == 2)
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[1][0] * A->matrix[0][1];
      else if (A->rows >= 3) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t M = {0};
          res = minor_matrix(A, 0, j, &M);
          if (!res) {
            double det = 0.0;
            res = determinant(&M, &det);
            if (!res) *result += pow(-1, j) * A->matrix[0][j] * det;
            remove_matrix(&M);
          }
        }
      }
    } else
      res = CALCULATION_ERROR;
  } else
    res = INCORRECT_MATRIX;
  return res;
}