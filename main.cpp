#include <iostream>
#include "classes.h"

int main(int argc, char const *argv[]) {
    Matrix A{2, 2};
    Matrix B{2, 2};

    A.getFullMatrix();
    B.getFullMatrix();

    A.printMatrix();
    B.printMatrix();

    Matrix C = A + B;

    C.printMatrix();

    A = B * C;

    A.printMatrix();

    Matrix D{3, 2};
    Matrix E{2, 3};

    D.getFullMatrix();
    E.getFullMatrix();

    std::cout << "D (2, 1) * E (1, 3)" << std::endl;

    Matrix F = D * E;

    F.printMatrix();

    F = E * D;

    F.printMatrix();

    return 0;
}
