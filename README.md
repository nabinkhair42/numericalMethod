# Numerical Methods in C

This repository contains implementation of various numerical methods algorithms in C programming language. These programs are designed to help students understand and solve mathematical problems using computer programming.


### Chapter 2: Linear Algebra
- **Gauss Elimination** (`chapter2/gaussElimination.c`)
  - Solves system of linear equations using forward elimination and back substitution
  - Good for smaller systems of equations

- **Gauss Jordan** (`chapter2/gaussJordan.c`)
  - Solves system of linear equations by converting to reduced row echelon form
  - Gives direct solution without back substitution

- **Matrix Inversion** (`chapter2/matrixInversion.c`)
  - Finds the inverse of a square matrix
  - Important for solving multiple systems with same coefficient matrix

- **Eigen Value** (`chapter2/eigenValue.c`)
  - Calculates eigenvalues and eigenvectors using power method
  - Useful in various engineering applications

### Helper Functions
The `matrixHelper.h` file contains common functions for:
- Matrix input
- Matrix display
- Solution vector display


## Input Format
- First enter the size of the system (number of equations)
- Then enter the coefficients as prompted
- For augmented matrices, enter the constants in the last column

## Notes
- Maximum matrix size is set to 15×15 (can be modified in N define)
- All programs include error checking for mathematical validity
- Programs use float data type for calculations

## Contributing
Feel free to contribute by:
- Adding new numerical methods
- Improving existing implementations
- Adding documentation and examples
- Reporting bugs

Happy Computing!
