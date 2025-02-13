// Matrix inversion

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

    inputMatrix(arr, n, n, "Enter the matrix to invert:");
    displayMatrix(arr, n, n, "The input matrix is:");

    // Perform Matrix Inversion
    for (i = 0; i < n; i++)
    {
        if (arr[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ratio = arr[j][i] / arr[i][i];
                for (k = 0; k < n; k++)
                {
                    arr[j][k] = arr[j][k] - ratio * arr[i][k];
                }
            }
        }
    }

    // Normalize the equations
    for (i = 0; i < n; i++)
    {
        x[i] = arr[i][n] / arr[i][i];
    }

    displaySolution(x, n);

    return 0;
}