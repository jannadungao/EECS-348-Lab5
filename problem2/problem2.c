#include <stdio.h>
#include <string.h>
#define SIZE 5

// add matrices
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int mnew[SIZE][SIZE]) {
    // check if you can add
    if (sizeof(m1[SIZE][SIZE]) != sizeof(m2[SIZE][SIZE])) {
        printf("Incompatible matrix dimensions for addition");
        return 0; 
    }
    // do addition
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            mnew[row][col] = m1[row][col] + m2[row][col];
        }
    }
}

// multiply matrices
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int mnew[SIZE][SIZE]) {
    // check if multiplication is possible (cols of m1 == rows of m2)
    if (sizeof(m1[0]) != sizeof(m1)) {
        printf("Incompatible matrix dimensions for multiplication");
        return 0;
    }

    // do multiplication
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            mnew = 0;
            for (int i = 0; i < SIZE; i++) {
                mnew += m1[row][i] * m2[i][col];
            }
        }
    }
}


// transpose matrices
int transposeMatrix(int m[SIZE][SIZE], int mnew[SIZE][SIZE]) {
    int mnew[SIZE][SIZE];

    for (int col = 0; col < SIZE; col++) {
        for (int row = 0; row < sizeof(m); row++) {
            mnew[col][row] = m[row][col];
        }
    }
}

// print matrix
void printMatrix(int m[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        printf("%d\n", *m[row]);
    }
}

int main() {
    // Define matrices/input
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
    printMatrix(m3[SIZE][SIZE]);

    printf("Multiplication of Matrices: \n");
    int m4[SIZE][SIZE];
    multiplyMatrices(m1, m2, m4);
    printMatrix(m4[SIZE][SIZE]);

    printf("Tranpsposition of first matrix: \n");
    int m5[SIZE][SIZE];
    transposeMatrix(m1, m5);
    printMatrix(m5[SIZE][SIZE]);

    printf("Transposition of second matrix: \n");
    int m6[SIZE][SIZE];
    transposeMatrix(m2, m6);
    printMatrix(m6[SIZE][SIZE]);    
    
    return 0;
}