#include "Matrix.h"

int main() {
    std::cout << "Input sizes of matrix:" << std::endl;
    int n, m;
    std::cin >> n >> m;
    Matrix matrix = Matrix(n, m);
    std::cout << "___________________" << std::endl;
    std::cout << "The matrix:" << std::endl;
    matrix.createMatrix();
    matrix.printMatrix();
    matrix.sortMatrix();
    std::cout << "___________________" << std::endl;
    std::cout << "Sorted matrix:" << std::endl;
    matrix.printMatrix();
    std::cout << "___________________" << std::endl;
    matrix.deleteStrings();
    std::cout << "Matrix without strings with max sum of elements:" << std::endl;
    matrix.printMatrix();
    getch();
    return 0;
}
