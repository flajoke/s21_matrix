#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int i, j, k;
  double **matrix;
  double det;
  if (A->rows != A->columns) return INCORRECT_MATRIX;
  matrix = (double **)malloc(A->rows * sizeof(double *));
  if (matrix == NULL) return INCORRECT_MATRIX;
  for (i = 0; i < A->rows; i++) {
    matrix[i] = (double *)malloc(A->columns * sizeof(double));
    if (matrix[i] == NULL) return INCORRECT_MATRIX;
    for (j = 0; j < A->columns; j++) matrix[i][j] = A->matrix[i][j];
  }
  det = 1.0;
  for (i = 0; i < A->rows; i++) {
    int max = i;
    for (j = i + 1; j < A->rows; j++)
      if (fabs(matrix[j][i]) > fabs(matrix[max][i])) max = j;
    if (max != i) {
      det *= -1;
      for (k = 0; k < A->rows; k++) {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[max][k];
        matrix[max][k] = temp;
      }
    }
    if (matrix[i][i] == 0) {
      det = 0;
      break;
    }
    det *= matrix[i][i];
    for (j = i + 1; j < A->rows; j++) {
      double factor = matrix[j][i] / matrix[i][i];
      for (k = i; k < A->rows; k++) matrix[j][k] -= factor * matrix[i][k];
    }
  }
  for (i = 0; i < A->rows; i++) free(matrix[i]);
  free(matrix);
  *result = det;
  return OK;
}