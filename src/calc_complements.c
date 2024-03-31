#include "matrix.h"

int calc_complements(matrix_t *A, matrix_t *result) {
  resulting_code res = OK;
  if (is_matrix(A)) {
    if (A->rows == A->columns) {
      res = create_matrix(A->rows, A->columns, result);
      if (!res) {
        if (A->rows == 1)
          result->matrix[0][0] = 1;
        else {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              matrix_t M = {0};
              res = minor_matrix(A, i, j, &M);
              if (!res) {
                double det = 0.0;
                res = determinant(&M, &det);
                if (!res) result->matrix[i][j] = pow(-1, i + j) * det;
                remove_matrix(&M);
              }
            }
          }
        }
      }
    } else
      res = CALCULATION_ERROR;
  } else
    res = INCORRECT_MATRIX;
  return res;
}