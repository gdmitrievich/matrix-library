<h1 align="center">Matrix Library</h1>

<h3 align="center">A custom C library for processing numerical matrices</h3>

<h2>Table of Contents</h2>

- [Features](#features)
- [Allowed Operations](#allowed-operations)
- [Tech Stack](#tech-stack)
- [Project Experience](#project-experience)
- [License](#license)

<h2 id="features">Features</h2>

- Performs basic linear algebra operations.
- Enables matrix transformations such as transpose, inversion, and determinant computation.
- Supports vector-matrix multiplications and element-wise operations.
- Uses a single memory area to store data, improving performance.

<h2 id="allowed-operations">Allowed Operations</h2>

> All operations (except matrix comparison) return the resulting code:
> - 0 - OK
> - 1 - Error, incorrect matrix
> - 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed, etc.)

### Creating matrices (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Cleaning of matrices (remove_matrix)

```c
void s21_remove_matrix(matrix_t *A);
```

### Matrix comparison (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
```
> The comparison continues up to and including 7 decimal places.

### Adding (sum_matrix) and subtracting matrices (sub_matrix)

```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Matrix multiplication by scalar (mult_number). Multiplication of two matrices (mult_matrix)

```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Matrix transpose (transpose)

```c
int s21_transpose(matrix_t *A, matrix_t *result);
```

### Minor of matrix and matrix of algebraic complements (calc_complements)

```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```

### Matrix determinant

```c
int s21_determinant(matrix_t *A, double *result);
```

### Inverse of the matrix (inverse_matrix)

```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

<h2 id="tech-stack">Tech Stack</h2>

- Language: C (C11).
- Build System: Makefile.
- Unit Testing: Check library (check.h).
- Version Control: git & GitFlow workflow.
- Coverage Reporting: `gcov` utility.

<h2 id="project-experience">Project Experience</h2>

In this project I consolidated structured programming, matrix operations, clean code principles and encapsulation.

I practised:
- Encapsulation: creating an interface for accessing data through functions that hide implementation details and the data itself. There was no need to access the data directly.
- Version Controlling with git & GitFlow workflow.
- Building project with Makefile.
- Writing unit tests using AAA pattern.
- Creating test coverage that covers 100% of functions & 98% of lines of code.
- Error Handling: solution prevents crashes or undefined behaviors.
- Clean code principles and practices:
	- Single Responsibility Principle (SRP): each function performs a single responsibility without side effects.
	- Modularity: functions are grouped logically based on functionality (arithmetic, comparison, math etc.).
	- D.R.Y. (Don't Repeat Yourself): avoid duplicated code blocks.
	- Code is self-explanatory and easily readable.
		- The function names reflects their implementation.
		- Magic numbers were replaced with the enums and macros to enhanse readability.
		- The code was written according to [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

<h2 id="license">License</h2>

MIT © [Gleb Dmitrievich](https://github.com/gdmitrievich)