# In-Place Dynamic Matrix Transposition in C

A CLI program written in C that transposes an arbitrary rectangular 2D matrix directly via pointer reference (in-place replacement), safely updating dimensions and memory allocation.

## Features

- **In-Place Replacement:** The function takes a pointer to an existing matrix (`int***`), allocates the transposed layout, frees the original matrix, and updates the pointer and dimensions directly.
- **Dynamic Memory Management:** Handles non-square matrices (rows != columns) safely with dynamic memory allocation (`malloc` and `free`).
- **Memory Leak Protection:** Cleans up properly in all branches; handles partial-allocation failures gracefully without dangling pointers.
- **Valgrind Verified:** 0 memory leaks and 0 memory errors under strict checks.

## Principle

Given a matrix A of dimensions R x S:
- Transposed matrix A^T has dimensions S x R.
- Each element is mapped as: A^T[i][j] = A[j][i].

## How to Build and Run

### 1. Compilation
Compile with strict flags:
```bash
gcc -Wall -pedantic -g transpoziceMaticeNaMiste.c -o transpose
```

### 2. Execution
```bash
./transpose
```

### 3. Check for Memory Leaks (Valgrind)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./transpose
```

## Example Usage

```text
Zadej rozmery matice (radky sloupce):
2 3
Zadejte prvky matice:
1 2 3
4 5 6
Transponovana matice:
1 4
2 5
3 6
```
