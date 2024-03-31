#include "matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  resulting_code res = OK;
  if (is_matrix(A)) {
    res = create_matrix(A->columns, A->rows, result);
    if (!res) {
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  } else
    res = INCORRECT_MATRIX;
  return res;
}