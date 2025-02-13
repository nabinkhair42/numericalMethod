// Eigen Value by Power Method

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
    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    inputMatrix(arr, n, n, "Enter the matrix elements:");
    displayMatrix(arr, n, n, "The input matrix is:");

    // Perform Eigen Value by Power Method
    float lambda = 0, lambda_old = 0, error = 0.0001;
    for (i = 0; i < n; i++)
    {
        x[i] = 1;
    }
    do
    {
        for (i = 0; i < n; i++)
        {
            x[i] = 0;
            for (j = 0; j < n; j++)
            {
                x[i] = x[i] + arr[i][j] * x[j];
            }
        }
        lambda_old = lambda;
        lambda = 0;
        for (i = 0; i < n; i++)
        {
            lambda = lambda + x[i] * x[i];
        }
        lambda = sqrt(lambda);
        for (i = 0; i < n; i++)
        {
            x[i] = x[i] / lambda;
        }
    } while (fabs(lambda - lambda_old) > error);

    // Display the solution
    printf("\nThe Eigen Value is: %f\n", lambda);
    displaySolution(x, n);  // Using helper to display eigen vector
    return 0;
}