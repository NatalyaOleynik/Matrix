#include "matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  resulting_code res = OK;
  double det = 0.0;
  res = determinant(A, &det);
  if (!res) {
    if (fabs(det) > 1e-7) {
      matrix_t MCC = {0};
      res = calc_complements(A, &MCC);
      if (!res) {
        matrix_t MCCT = {0};
        res = transpose(&MCC, &MCCT);
        if (!res) {
          if (!res) res = mult_number(&MCCT, 1 / det, result);
          remove_matrix(&MCCT);
        }
        remove_matrix(&MCC);
      }
    } else
      res = CALCULATION_ERROR;
  }
  return res;
}