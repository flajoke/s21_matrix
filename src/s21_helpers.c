#include "s21_matrix.h"

void get_submatrix(matrix_t *A, int rowToRemove, int colToRemove,
                   matrix_t *submatrix) {
  int rowIndex = 0, colIndex = 0;
  for (int row = 0; row < submatrix->rows; row++) {
    if (row == rowToRemove) rowIndex++;
    for (int col = 0; col < submatrix->columns; col++) {
      if (col == colToRemove) colIndex++;
      submatrix->matrix[row][col] = A->matrix[rowIndex][colIndex];
      colIndex++;
    }
    rowIndex++;
    colIndex = 0;
  }
}

int check_matrix(matrix_t *A) {
  int result = FAILURE;
  if (A && A->matrix && A->rows > 0 && A->columns > 0) result = SUCCESS;
  return result;
}

double get_determinant(matrix_t *A) {
  double flag = 0;
  if (A->rows == 1) {
    flag = A->matrix[0][0];
  } else {
    matrix_t tmp;
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      get_submatrix(A, 0, i, &tmp);
      if (i % 2) {
        flag -= A->matrix[0][i] * get_determinant(&tmp);
      } else {
        flag += A->matrix[0][i] * get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return flag;
}

int s21_is_correct_(matrix_t *A) {
  int flag = 0;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    flag = 1;
  }
  return flag;
}