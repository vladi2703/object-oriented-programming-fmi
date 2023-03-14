#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
 public:
  Matrix(int rows, int cols);
  ~Matrix();
  Matrix(const Matrix& other);

  Matrix& operator=(const Matrix& other);
  Matrix(Matrix&& other);
  Matrix& operator=(Matrix&& other);

  int& operator()(int row, int col);  // lvalue

  Matrix operator+(const Matrix& other) const;

  Matrix operator-(const Matrix& other) const;

  Matrix operator*(const Matrix& other) const;

  bool operator==(const Matrix& other) const;

  friend Matrix transpose(const Matrix& matrix);

  friend void print(const Matrix& matrix);

 private:
  void copy(const Matrix& other);
  void destroy();

  int m_rows;
  int m_cols;
  int** m_data;
};

#endif  // MATRIX_H