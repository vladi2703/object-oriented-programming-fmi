#include "matrix.h"

#include <iostream>

void Matrix::copy(const Matrix& other) {
  m_rows = other.m_rows;
  m_cols = other.m_cols;
  m_data = new int*[m_rows];
  for (int i = 0; i < m_rows; i++) {
    m_data[i] = new int[m_cols];
    for (int j = 0; j < m_cols; j++) {
      m_data[i][j] = other.m_data[i][j];
    }
  }
}

void Matrix::destroy() {
  for (int i = 0; i < m_rows; i++) {
    delete[] m_data[i];
  }
  delete[] m_data;
}

Matrix::Matrix(int rows, int cols) {
  m_rows = rows;
  m_cols = cols;
  m_data = new int*[m_rows];
  for (int i = 0; i < m_rows; i++) {
    m_data[i] = new int[m_cols];
    for (int j = 0; j < m_cols; j++) {
      m_data[i][j] = 0;
    }
  }
}

Matrix::~Matrix() { this->destroy(); }

Matrix::Matrix(const Matrix& other) { this->copy(other); }

Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    this->destroy();
    this->copy(other);
  }
  return *this;
}

Matrix::Matrix(Matrix&& other) {
  // Here we take the data from the other object and put it in our object.
  // !! We do not copy the data, we take it from the other object.
  m_rows = other.m_rows;
  m_cols = other.m_cols;
  m_data = other.m_data;
  // Here we reset the other object.
  other.m_rows = 0;
  other.m_cols = 0;
  other.m_data = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) {
  if (this != &other) {
    // we should delete the data in our object,
    // otherwise we will have a memory leak.
    this->destroy();

    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_data = other.m_data;
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_data = nullptr;
  }
  return *this;
}

/**
 * @brief This function returns a reference to the element in the matrix.
 * @param row The row of the element.
 * @param col The column of the element.
 * @return A reference to the element in the matrix.
 */
int& Matrix::operator()(int row, int col) {
  return m_data[row][col];
  // Here we return a reference to the element in the matrix.
  // This means that we can use the operator() both as an lvalue and as an
  // rvalue. We can change the value of the element in the matrix, or we can
  // read it.
}

/**
 * @brief This function returns a new matrix which is the sum of the current
 * matrix and the other matrix.
 * @param other The other matrix.
 * @return A new matrix which is the sum of the current matrix and the other
 * */
Matrix Matrix::operator+(const Matrix& other) const {
  Matrix result(m_rows, m_cols);
  for (int i = 0; i < m_rows; i++) {
    for (int j = 0; j < m_cols; j++) {
      result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
    }
  }
  return result;
}

/**
 * @brief This function returns a new matrix which is the difference of the
 * current matrix and the other matrix.
 * @param other The other matrix.
 * @return A new matrix which is the difference of the current matrix and the
 * other matrix.
 */
Matrix Matrix::operator-(const Matrix& other) const {
  Matrix result(m_rows, m_cols);
  for (int i = 0; i < m_rows; i++) {
    for (int j = 0; j < m_cols; j++) {
      result.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
    }
  }
  return result;
}

/**
 * @brief This function returns a new matrix which is the product of the
 * current matrix and the other matrix.
 * @param other The other matrix.
 * @return A new matrix which is the product of the current matrix and the
 * other matrix.
 */
Matrix Matrix::operator*(const Matrix& other) const {
  Matrix result(m_rows, other.m_cols);
  for (int i = 0; i < m_rows; i++) {
    for (int j = 0; j < other.m_cols; j++) {
      for (int k = 0; k < m_cols; k++) {
        result.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
      }
    }
  }
  return result;
}

/**
 * @brief This function returns true if the current matrix is equal to the
 * other matrix.
 * @param other The other matrix.
 * @return True if the current matrix is equal to the other matrix, false
 * otherwise.
 */
bool Matrix::operator==(const Matrix& other) const {
  if (m_rows != other.m_rows || m_cols != other.m_cols) {
    return false;
  }
  for (int i = 0; i < m_rows; i++) {
    for (int j = 0; j < m_cols; j++) {
      if (m_data[i][j] != other.m_data[i][j]) {
        return false;
      }
    }
  }
  return true;
}

/**
 * @brief This function returns a new matrix which is the transpose of the
 * passed matrix.
 * @param matrix The matrix which we want to transpose.
 * @return A new matrix which is the transpose of the current matrix.
 */
Matrix transpose(const Matrix& matrix) {
  Matrix result(matrix.m_cols, matrix.m_rows);
  for (int i = 0; i < matrix.m_rows; i++) {
    for (int j = 0; j < matrix.m_cols; j++) {
      result.m_data[j][i] = matrix.m_data[i][j];
    }
  }
  return result;
}

/**
 * @brief This function prints the passed matrix.
 * @param matrix The matrix which we want to print.
 */
void print(const Matrix& matrix) {
  for (int i = 0; i < matrix.m_rows; i++) {
    for (int j = 0; j < matrix.m_cols; j++) {
      std::cout << matrix.m_data[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  print(a);

  Matrix b(2, 2);
  b(0, 0) = 5;
  b(0, 1) = 6;
  b(1, 0) = 7;
  b(1, 1) = 8;
  print(b);

  Matrix c = a + b;
  print(c);

  Matrix d = a - b;
  print(d);

  Matrix e = a * b;
  print(e);

  if (a == b) {
    std::cout << "a is equal to b" << std::endl;
  } else {
    std::cout << "a is not equal to b" << std::endl;
  }

  Matrix f = a;
}