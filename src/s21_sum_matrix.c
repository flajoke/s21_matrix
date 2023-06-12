#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int i, j;
  if (A->rows != B->rows || A->columns != B->columns) return INCORRECT_MATRIX;
  result->rows = A->rows;
  result->columns = A->columns;
  result->matrix = (double **)malloc(result->rows * sizeof(double *));
  if (result->matrix == NULL) return INCORRECT_MATRIX;
  for (i = 0; i < result->rows; i++) {
    result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
    if (result->matrix[i] == NULL) return INCORRECT_MATRIX;
    for (j = 0; j < result->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }
  return OK;
}