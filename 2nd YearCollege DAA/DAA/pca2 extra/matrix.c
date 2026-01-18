#include <stdio.h>

// Function to multiply two matrices
void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to take matrix input
void inputMatrix(int matrix[10][10], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;
    
    // User input for matrix sizes
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    
    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of first matrix must equal rows of second matrix.\n");
        return 0;
    }
    
    // Input matrices
    printf("Enter elements of first matrix:\n");
    inputMatrix(a, r1, c1);
    
    printf("Enter elements of second matrix:\n");
    inputMatrix(b, r2, c2);
    
    // Multiply matrices
    multiplyMatrices(a, b, result, r1, c1, c2);
    
    // Display result
    printf("Resultant Matrix:\n");
    printMatrix(result, r1, c2);
    
    return 0;
}

