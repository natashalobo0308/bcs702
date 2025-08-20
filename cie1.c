#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // For omp_get_wtime()

#define SIZE 1000  // You can increase this for longer execution time

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

    // Start timing using OpenMP wall-clock timer
    double start_time = omp_get_wtime();

    // Matrix multiplication (C = A x B)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // End timing
    double end_time = omp_get_wtime();

    // Print execution time
    printf("Matrix multiplication of size %d x %d completed.\n", SIZE, SIZE);
    printf("Execution time: %.6f seconds\n", end_time - start_time);

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
