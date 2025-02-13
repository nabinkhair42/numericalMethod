// ALL PROGRAM COMPILED IN SINGLE FILE FOR MENU DRIVEN ARCHITECTURE: MAKES EASY TO PRESENT. NOT GOOD IDEA FOR SCALING.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrixHelper.h"

#define N 15
#define CLEAR_SCREEN "cls"  // Use "clear" for Linux/Unix

// Function prototypes
void gaussElimination();
void gaussJordan();
void matrixInversion();
void eigenValue();
void clearScreen();
void pauseScreen();

int main() {
    int choice;
    do {
        clearScreen();
        printf("\n=== Numerical Methods Calculator ===\n");
        printf("1. Gauss Elimination Method\n");
        printf("2. Gauss Jordan Method\n");
        printf("3. Matrix Inversion\n");
        printf("4. Eigen Value (Power Method)\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        clearScreen();
        switch(choice) {
            case 1:
                printf("\n=== Gauss Elimination Method ===\n");
                gaussElimination();
                break;
            case 2:
                printf("\n=== Gauss Jordan Method ===\n");
                gaussJordan();
                break;
            case 3:
                printf("\n=== Matrix Inversion ===\n");
                matrixInversion();
                break;
            case 4:
                printf("\n=== Eigen Value Calculator ===\n");
                eigenValue();
                break;
            case 5:
                printf("Thank you for using Numerical Methods Calculator!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        pauseScreen();
    } while(choice != 5);

    return 0;
}

void gaussElimination() {
    float arr[N][N], x[N], ratio;
    int i, j, k, n;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    inputMatrix(arr, n, n+1, "Enter the augmented matrix [A|B]:");
    displayMatrix(arr, n, n+1, "The augmented matrix is:");

    // Forward elimination
    for(i = 0; i < n-1; i++) {
        if(arr[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for(j = i+1; j < n; j++) {
            ratio = arr[j][i]/arr[i][i];
            for(k = 0; k < n+1; k++) {
                arr[j][k] = arr[j][k] - ratio * arr[i][k];
            }
        }
    }

    // Back substitution
    x[n-1] = arr[n-1][n]/arr[n-1][n-1];
    for(i = n-2; i >= 0; i--) {
        x[i] = arr[i][n];
        for(j = i+1; j < n; j++) {
            x[i] = x[i] - arr[i][j]*x[j];
        }
        x[i] = x[i]/arr[i][i];
    }

    displaySolution(x, n);
}

void gaussJordan() {
    float arr[N][N], x[N], ratio;
    int i, j, k, n;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    inputMatrix(arr, n, n+1, "Enter the augmented matrix [A|B]:");
    displayMatrix(arr, n, n+1, "The augmented matrix is:");

    // Gauss Jordan Elimination
    for(i = 0; i < n; i++) {
        if(arr[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for(j = 0; j < n; j++) {
            if(i != j) {
                ratio = arr[j][i]/arr[i][i];
                for(k = 0; k < n+1; k++) {
                    arr[j][k] = arr[j][k] - ratio * arr[i][k];
                }
            }
        }
    }

    // Solution
    for(i = 0; i < n; i++) {
        x[i] = arr[i][n]/arr[i][i];
    }

    displaySolution(x, n);
}

void matrixInversion() {
    // ... Copy the content from matrixInversion.c ...
    printf("Matrix Inversion method (Implementation pending)\n");
}

void eigenValue() {
    float arr[N][N], x[N];
    int i, j, n;
    float lambda = 0, lambda_old = 0, error = 0.0001;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    inputMatrix(arr, n, n, "Enter the matrix elements:");
    displayMatrix(arr, n, n, "The input matrix is:");

    // Initialize eigenvector
    for(i = 0; i < n; i++) x[i] = 1;

    // Power method iteration
    do {
        for(i = 0; i < n; i++) {
            float sum = 0;
            for(j = 0; j < n; j++) {
                sum += arr[i][j] * x[j];
            }
            x[i] = sum;
        }
        
        lambda_old = lambda;
        lambda = 0;
        for(i = 0; i < n; i++) {
            lambda += x[i] * x[i];
        }
        lambda = sqrt(lambda);
        
        for(i = 0; i < n; i++) {
            x[i] /= lambda;
        }
    } while(fabs(lambda - lambda_old) > error);

    printf("\nDominant Eigenvalue = %f\n", lambda);
    printf("Corresponding Eigenvector:\n");
    displaySolution(x, n);
}

void clearScreen() {
    system(CLEAR_SCREEN);
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
