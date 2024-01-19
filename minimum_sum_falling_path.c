#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    // Helper function to find the minimum of three values
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    // Check for an empty matrix
    if (matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0) {
        return 0;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Iterate through each row starting from the second row
    for (int row = 1; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            // Calculate the minimum sum of falling paths
            matrix[row][col] += min(
                matrix[row - 1][col > 0 ? col - 1 : col],
                matrix[row - 1][col],
                matrix[row - 1][col < cols - 1 ? col + 1 : col]
            );
        }
    }

    // Find the minimum value in the last row
    int minSum = matrix[rows - 1][0];
    for (int col = 1; col < cols; col++) {
        if (matrix[rows - 1][col] < minSum) {
            minSum = matrix[rows - 1][col];
        }
    }

    return minSum;
}

int main() {
    int rows = 3;
    int cols = 3;

    // Dynamic memory allocation for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with values
    matrix[0][0] = 2; matrix[0][1] = 1; matrix[0][2] = 3;
    matrix[1][0] = 6; matrix[1][1] = 5; matrix[1][2] = 4;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    int matrixColSize[3] = {3, 3, 3};

    int output = minFallingPathSum(matrix, rows, matrixColSize);

    printf("Output: %d\n", output);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
