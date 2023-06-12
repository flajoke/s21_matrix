#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int i, j;
  result->rows = A->columns;
  result->columns = A->rows;
  result->matrix = (double **)malloc(result->rows * sizeof(double *));
  if (result->matrix == NULL) return INCORRECT_MATRIX;
  for (i = 0; i < result->rows; i++) {
    result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
    if (result->matrix[i] == NULL) return INCORRECT_MATRIX;
    for (j = 0; j < result->columns; j++)
      result->matrix[i][j] = A->matrix[j][i];
  }
  return OK;
}