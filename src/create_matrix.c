#include "matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  resulting_code res = OK;
  if (rows < 1 || columns < 1)
    res = INCORRECT_MATRIX;
  else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL)
      res = INCORRECT_MATRIX;
    else
      for (int i = 0; i < rows; i++)
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }
  return res;
}