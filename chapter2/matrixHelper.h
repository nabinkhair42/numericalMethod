#ifndef MATRIX_HELPER_H
#define MATRIX_HELPER_H

#include <stdio.h>

// Function to input matrix elements
void inputMatrix(float matrix[][15], int rows, int cols, const char* message) {
    printf("%s\n", message);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(float matrix[][15], int rows, int cols, const char* message) {
    printf("\n%s\n", message);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to display solution vector
void displaySolution(float x[], int n) {
    printf("\nThe solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }
}

#endif
