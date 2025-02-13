// Gauss Elimination Method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrixHelper.h"

#define N 15 // Maximum array size

int main()
{
    float arr[N][N], x[N], ratio; // arr: array to store the coefficients of the equations and the RHS values, x: array to store the solution of the equations and ratio: to store the ratio of the coefficients
    int i, j, k, n;               // i, j, k: loop variables and n: number of equations

    // Take the number of equations as input
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    inputMatrix(arr, n, n+1, "Enter the augmented matrix [A|B]:");
    displayMatrix(arr, n, n+1, "The augmented matrix is:");

    // Perform Gauss Elimination
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = i + 1; j < n; j++)
        {
            ratio = arr[j][i] / arr[i][i];
            for (k = 0; k < n + 1; k++)
            {
                arr[j][k] = arr[j][k] - ratio * arr[i][k];
            }
        }
    }

    // Back Substitution

    x[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        x[i] = arr[i][n];
        for (j = i + 1; j < n; j++)
        {
            x[i] = x[i] - arr[i][j] * x[j];
        }
        x[i] = x[i] / arr[i][i];
    }

    displaySolution(x, n);
    return 0;
}