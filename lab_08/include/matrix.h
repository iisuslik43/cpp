#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include <cstdio>
#include <cstddef>

class Matrix {
public:
  Matrix(const Matrix &matrixToCopy ); // конструктор копии
  ~Matrix(); // десструктор класса Matrix
  Matrix(std::size_t r, std::size_t c);

  std::size_t get_rows()const;
  std::size_t get_cols()const;
  void set(std::size_t i, std::size_t j, int val);
  int get(std::size_t i, std::size_t j)const;
  void print(FILE *f)const;
  
  Matrix operator=(const Matrix& m);
  Matrix operator+(const Matrix& m)const;
  Matrix operator-(const Matrix& m)const;
  Matrix operator*(const Matrix& m)const;

  Matrix& operator+=(const Matrix& m);
  Matrix& operator-=(const Matrix& m);
  Matrix& operator*=(const Matrix& m);

  bool operator==(const Matrix& m)const;
  bool operator!=(const Matrix& m)const;
private:
  std::size_t _rows;
  std::size_t _cols;
  int **_data;
};

#endif
