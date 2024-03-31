#include "matrix.h"

int is_matrix(matrix_t *matrix) {
  int res = 1;
  if (!matrix || !matrix->matrix || matrix->rows <= 0 || matrix->columns <= 0)
    res = 0;
  return res;
}

int minor_matrix(matrix_t *A, int row, int column, matrix_t *M) {
  resulting_code res = OK;
  res = create_matrix(A->rows - 1, A->columns - 1, M);
  if (!res) {
    for (int i = 0; i < A->rows; i++) {
      if (i == row) continue;
      for (int j = 0; j < A->columns; j++) {
        if (j == column) continue;
        M->matrix[i < row ? i : i - 1][j < column ? j : j - 1] =
            A->matrix[i][j];
      }
    }
  }
  return res;
}