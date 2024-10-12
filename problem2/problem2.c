#include <stdio.h>
#include <string.h>
#define SIZE 5

// add matrices
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    // check if you can add
    if (sizeof(m1[SIZE][SIZE]) != sizeof(m2[SIZE][SIZE])) {
        printf("Incompatible matrix dimensions for addition");
        return 0; 
    }
    // do addition
    int mnew[SIZE][SIZE];

    for (int row = 0; row < sizeof(m1); row++) {
        for (int col = 0; col < sizeof(m1[0]); col++) {
            mnew[row][col] = m1[row][col] + m2[row][col];
        }
    }
    return mnew[SIZE][SIZE];
}

// multiply matrices
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    // check if multiplication is possible (cols of m1 == rows of m2)
    if (sizeof(m1[0]) != sizeof(m1)) {
        printf("Incompatible matrix dimensions for multiplication");
        return 0;
    }

    // do multiplication
    int mnew[sizeof(m1)][sizeof(m2[0])];

    for (int row = 0; row < sizeof(m1); row++) {
        int val = 0;
        for (int col = 0; col < sizeof(m2[0]); col++) {
            val = val + m1[row][col] + m2[col][0];
        }
    }
    return mnew[sizeof(m1)][sizeof(m2[0])];
}


// transpose matrices
int transposeMatrix(int m[SIZE][SIZE]) {
    int mnew[SIZE][SIZE];

    for (int col = 0; col < sizeof(m[0]); col++) {
        for (int row = 0; row < sizeof(m); row++) {
            mnew[col][row] = m[row][col];
        }
    }

    return mnew[SIZE][SIZE];
}

// print matrix
void printMatrix(int m) {
    for (int row = 0; row < sizeof(m); row++) {
        printf("%d\n", m[row]);
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
    printMatrix(addMatrices(m1, m2));

    printf("Multiplication of Matrices: \n");
    printMatrix(multiplyMatrices(m1, m2));

    printf("Tranpsposition of first matrix: \n");
    printMatrix(transposeMatrix(m1));

    printf("Transposition of second matrix: \n");
    printMatrix(transposeMatrix(m2));    
}