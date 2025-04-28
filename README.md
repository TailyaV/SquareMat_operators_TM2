##README FILE- Square Matrix Operators

##Project Overview
The **SquareMat** project implements a C++ class that represents square matrices (matrices where the number of rows equals the number of columns).  
The class supports various constructors, mathematical operations, logical comparisons, and special matrix operations like determinant calculation and transposition.  

The goal is to allow natural, safe, and efficient manipulation of square matrices using intuitive syntax through operator overloading.

##Setup and Compilation
To compile and run the project, follow these steps:
1. Clone the repository.
2. Compile the code use a C++ compiler.
3. Options: 
make Main- to run the demo file.
make test- to run the unit test.
make valgrind- memory leak testing using valgrind.
make clean- deletes all irrelevant files after running.

##Class
class: SquareMat

Functions:
### Constructors
- `SquareMat(int size)` — Initializes an empty square matrix (filled with zeros).
- `SquareMat(int size, double arr[], int arrSize)` — Initializes a matrix using a 1D array.
- Copy constructor and assignment operator (deep copy support).

### Destructor
- `~SquareMat()` — Frees dynamically allocated memory.

## Mathematical Operators
- `+` — Matrix addition / scalar addition to each element.
- `-` — Matrix subtraction / negation of the matrix.
- `*` — Matrix multiplication / scalar multiplication.
- `/` — Division of all elements by a scalar (non-zero).
- `%` — Element-wise multiplication between matrices or element-wise modulo by a scalar.
- `^` — Matrix exponentiation (integer powers only).
- `!` — Calculates the determinant of the matrix.
- `~` — Returns the transpose of the matrix.

## Logical Operators
- `==, !=` — Compare matrices based on the sum of their elements.
- `<, <=, >, >=` — Compare matrices based on the sum of elements.

## Additional Operators
- `++` — Increments all elements by 1 (both prefix and postfix).
- `--` — Decrements all elements by 1 (both prefix and postfix).
- `[i]` — Access the i-th row (both for reading and writing).
- `<<` — Prints the matrix nicely formatted to an output stream.