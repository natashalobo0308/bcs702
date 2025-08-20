cie1.c

**Matrix Multiplication Program**
Description
This program performs multiplication of two large square matrices (size: SIZE x SIZE) filled with random integers. It demonstrates how to measure the execution time of a computationally intensive task in C, both without and with OpenMP timing support.

**1. Without OpenMP (using clock())**
Dynamically allocates memory for three matrices: A, B, and C.
Initializes A and B with random integer values.
Performs matrix multiplication using a triple nested loop:
Each element of the result matrix C is computed as the dot product of a row from A and a column from B.
Uses the standard C library function clock() to measure CPU time spent during multiplication.
Outputs the size of the matrices and the CPU execution time.
Frees all dynamically allocated memory after completion.

Notes:
clock() measures CPU processing time, which might be less precise or show zero for very fast operations.
The program runs serially (single-threaded).

**2. With OpenMP Timing (using omp_get_wtime())**
The matrix multiplication algorithm remains the same as above.
Instead of clock(), it uses OpenMP’s omp_get_wtime() to measure wall-clock time with high resolution.
Requires including the OpenMP header (omp.h) and compiling with the -fopenmp flag.
Provides more accurate timing results, especially for benchmarking.
Measures real elapsed time (wall-clock time), which is useful even if the code runs serially.

Advantages:
Higher timing precision compared to clock().
Suitable for both serial and parallel implementations.
Facilitates performance analysis and comparison.
