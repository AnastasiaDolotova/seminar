#include "Matrix.h"

void Matrix::createMatrix() {
    srand(time(nullptr));
    for (int i = 0; i < amount_of_strings; ++i) {
        *(matrix + i) = new int[amount_of_columns];
        for (int j = 0; j < amount_of_columns; ++j) {
            *(*(matrix + i) + j) = rand() % 100;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < amount_of_strings; ++i) {
        for (int j = 0; j < amount_of_columns; ++j) {
            std::cout << std::setw(4) << *(*(matrix + i) + j);
        }
        std::cout << std::endl;
    }
}

/**
 * Even strings are sorted in ascending order
 * Odd strings - in descending order
 */
void Matrix::sortMatrix() {
    for (int i = 0; i < amount_of_strings; ++i) {
        if (i % 2) {
            std::sort(*(matrix + i), *(matrix + i) + amount_of_columns);
        } else {
            std::sort(*(matrix + i), *(matrix + i) + amount_of_columns);
            std::reverse(*(matrix + i), *(matrix + i) + amount_of_columns);
        }
    }
}

/**
 *
 * @return max sum of elements in strings
 */
int Matrix::findMaxSum() {
    int maxSum = 0, i, sums[amount_of_strings];
    for (i = 0; i < amount_of_strings; ++i) {
        int sum = 0;
        for (int j = 0; j < amount_of_columns; ++j) {
            sum += *(*(matrix + i) + j);
        }
        sums[i] = sum;
    }
    for (i = 0; i < amount_of_strings; ++i) {
        if (sums[i] > maxSum) maxSum = sums[i];
    }
    return maxSum;
}

void Matrix::deleteStrings() {
    int maxSum = findMaxSum();
    std::cout << "Max sum of elements in strings: " << maxSum << std::endl;
    for (int i = 0; i < amount_of_strings; ++i) {
        int sum = 0;
        for (int j = 0; j < amount_of_columns; ++j) {
            sum += *(*(matrix + i) + j);
        }
        if (sum == maxSum) {
            for (int j = i; j < amount_of_strings - 1; ++j) {
                for (int k = 0; k < amount_of_columns; ++k){
                    *(*(matrix + j) + k) = *(*(matrix + j + 1) + k);
                }
            }
            delete[] *(matrix + amount_of_strings - 1);
            --amount_of_strings;
        }
    }
}
