#include "matrix.h"

void remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}