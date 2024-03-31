#include "matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  resulting_code res = OK;
  if (is_matrix(A)) {
    res = create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  } else
    res = INCORRECT_MATRIX;
  return res;
}