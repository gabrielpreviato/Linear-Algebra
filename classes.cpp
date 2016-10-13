#include "classes.h"

void Matrix::free() {
    for (int i = 0; i < _row; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}

Matrix::Matrix(){
    _col = _row = 0;
    _matrix = nullptr;
}

Matrix::Matrix(int rows, int cols) {
    _row = rows;
    _col = cols;

    _matrix = new double*[_row];
    for (int i = 0; i < _row; i++) {
        _matrix[i] = new double[_col];
        for (int j = 0; j < _col; j++) {
            _matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix & matrix) {
    _row = matrix._row;
    _col = matrix._col;

    _matrix = new double*[_row];
    for (int i = 0; i < _row; i++) {
        _matrix[i] = new double[_col];
        for (int j = 0; j < _col; j++) {
            _matrix[i][j] = matrix._matrix[i][j];
        }
    }

}

Matrix::~Matrix() {
    free();
}

Matrix & Matrix::operator=(const Matrix & matrix) {
    if (this == &matrix) {
        return *this;
    }
    free();
    _row = matrix._row;
    _col = matrix._col;

    _matrix = new double*[_row];
    for (int i = 0; i < _row; i++) {
        _matrix[i] = new double[_col];
        for (int j = 0; j < _col; j++) {
            _matrix[i][j] = matrix._matrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix matrix) {
    Matrix result {_row, _col};

    if (_row == matrix._row && _col == matrix._col) {
        result._matrix = new double*[result._row];
        for (int i = 0; i < result._row; i++) {
            result._matrix[i] = new double[result._col];
            for (int j = 0; j < result._col; j++) {
                result._matrix[i][j] = _matrix[i][j] + matrix._matrix[i][j];
            }
        }
    }

    else {
        std::cout << "Matrices with different sizes" << std::endl;
    }

    return result;
}

Matrix Matrix::operator*(const Matrix matrix) {
    Matrix result {_row, matrix._col};

    if (_col == matrix._row) {
        result._matrix = new double*[result._row];
        for (int i = 0; i < result._row; i++) {
            result._matrix[i] = new double[result._col];
            for (int j = 0; j < result._col; j++) {
                double value = 0;
                for (int k = 0; k < _col; k++) {
                    value += _matrix[i][k] * matrix._matrix[k][j];
                }

                result._matrix[i][j] = value;
            }
        }
    }

    else {
        std::cout << "Matrices with different collum and row sizes" << std::endl;
    }

    return result;
}

void Matrix::printMatrix() {
    for (int i = 0; i < _row; i++) {
        std::cout << "| ";
        for (int j = 0; j < _col; j++) {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << "|"<< std::endl;
    }
}

void Matrix::getFullMatrix() {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            std::cout << "a" << i + 1 << j + 1 << ": ";
            std::cin >> _matrix[i][j];
        }
    }
}
