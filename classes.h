#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class Matrix {
private:
    int _row, _col;
    double **_matrix;
    void free();
public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();
    Matrix(const Matrix & matrix);
    Matrix & operator=(const Matrix & matrix);
    Matrix operator+(const Matrix matrix);
    Matrix operator*(const Matrix matrix);
    void printMatrix();
    void getFullMatrix();
};

#endif
