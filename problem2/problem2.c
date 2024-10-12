#include <stdio.h>
#define SIZE 5

// add matrix
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int mnew[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            mnew[row][col] = m1[row][col] + m2[row][col]; // complete addition
        }
    }
}

// multiply matrix
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int mnew[SIZE][SIZE]) {
    // do multiplication
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            mnew[row][col] = 0; // initialize to 0
            for (int i = 0; i < SIZE; i++) {
                mnew[row][col] += m1[row][i] * m2[i][col]; // multiple rows of m1 by columns of m2
            }
        }
    }
}

// transpose matrix
void transposeMatrix(int m[SIZE][SIZE], int mnew[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            mnew[col][row] = m[row][col]; // make rows the columns and the columns the rows
        }
    }
}

// print matrix
void printMatrix(int m[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", m[row][col]); // print each row
        }
        printf("\n");
    }
}

int main() {
    // define matrices/input
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // function calls
    printf("Addition of Matrices: \n");
    int m3[SIZE][SIZE];
    addMatrices(m1, m2, m3);
    printMatrix(m3);

    printf("Multiplication of Matrices: \n");
    int m4[SIZE][SIZE];
    multiplyMatrices(m1, m2, m4);
    printMatrix(m4);

    printf("Transposition of first matrix: \n");
    int m5[SIZE][SIZE];
    transposeMatrix(m1, m5);
    printMatrix(m5);

    printf("Transposition of second matrix: \n");
    int m6[SIZE][SIZE];
    transposeMatrix(m2, m6);
    printMatrix(m6);

    return 0;
}