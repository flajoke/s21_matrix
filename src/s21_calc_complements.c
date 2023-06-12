#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (check_matrix(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = 1;
      } else {
        matrix_t submatrix = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &submatrix);
        for (int row = 0; row < A->rows; row++) {
          for (int col = 0; col < A->columns; col++) {
            get_submatrix(A, row, col, &submatrix);
            result->matrix[row][col] =
                pow(-1, row + col) * get_determinant(&submatrix);
          }
        }
        s21_remove_matrix(&submatrix);
      }
    } else {
      status = CALC_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}