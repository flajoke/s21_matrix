#include <math.h>

#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 0;
  double res = 0;
  matrix_t add_matr = {0};
  matrix_t trans_matr = {0};
  if (!s21_is_correct_(A)) {
    flag = 1;
  } else if (A->columns == A->rows && !s21_determinant(A, &res) && res != 0) {
    s21_transpose(A, &trans_matr);
    s21_calc_complements(&trans_matr, &add_matr);
    s21_mult_number(&add_matr, 1. / res, result);
    s21_remove_matrix(&add_matr);
    s21_remove_matrix(&trans_matr);
  } else {
    flag = 2;
  }
  return flag;
}