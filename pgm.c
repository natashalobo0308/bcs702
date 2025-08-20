#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000  // Increase to make it heavier, e.g. 1000 x 1000 matrix

int main() {
    // Allocate memory for matrices
    int **A = malloc(SIZE * sizeof(int *));
    int **B = malloc(SIZE * sizeof(int *));
    int **C = malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        A[i] = malloc(SIZE * sizeof(int));
        B[i] = malloc(SIZE * sizeof(int));
        C[i] = malloc(SIZE * sizeof(int));
    }

    // Initialize matrices A and B with random values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Record start time
    clock_t start = clock();

    // Matrix multiplication: C = A x B
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Record end time
    clock_t end = clock();

    // Calculate and print time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Matrix multiplication of size %d x %d completed.\n", SIZE, SIZE);
    printf("Execution time: %.4f seconds\n", time_taken);

    // Free allocated memory
    for (int i = 0; i < SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
