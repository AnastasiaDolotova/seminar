//
// Created by Kurrrrraga on 16.02.2022.
//

#ifndef SEMINAR_MATRIX_H
#define SEMINAR_MATRIX_H

class Matrix {
private:
    int **matrix;
    int amount_of_strings;
    int amount_of_columns;

    int findMaxSum();
public:
    Matrix(int n, int m){
        matrix = new int*[n];
        this->amount_of_strings = n;
        this->amount_of_columns = m;
    }

    void createMatrix();

    void printMatrix();

    void sortMatrix();

    void deleteStrings();

    ~Matrix(){
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
