#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <algorithm>

#ifndef SEMINAR_MATRIX_H
#define SEMINAR_MATRIX_H

class Matrix {
private:
    int **matrix;
    int amount_of_strings;
    int amount_of_columns;

    int findMaxSum();

public:
    Matrix(int n, int m) : amount_of_strings(n), amount_of_columns(m) {
        matrix = new int *[n];
    }

    Matrix(const Matrix &object) : amount_of_strings(object.amount_of_strings),
                                   amount_of_columns(object.amount_of_columns) {
        matrix = new int *[amount_of_strings];
        for (int i = 0; i < amount_of_strings; ++i) {
            *(matrix + i) = new int[amount_of_columns];
            for (int j = 0; j < amount_of_columns; ++j) {
                *(*(matrix + i) + j) = *(*(object.matrix + i) + j);
            }
        }
    }

    void createMatrix();

    void printMatrix();

    void sortMatrix();

    void deleteStrings();

    ~Matrix() {
        for (int i = 0; i < amount_of_strings; ++i) {
            delete[] *(matrix + i);
        }
        delete[] matrix;
    }

    int **getMatrix() {
        return matrix;
    }

    int getAmountOfStrings() const {
        return amount_of_strings;
    }

    int getAmountOfColumns() const {
        return amount_of_columns;
    }
};

#endif //SEMINAR_MATRIX_H
