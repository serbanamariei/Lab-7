# Lab 7 – Pointers and Dynamic Memory Allocation
This folder contains solved problems from Lab 7 of the "Programming Fundamentals" course.
## Topics Covered
- Basics of pointers and dynamic memory
- Dynamic allocation with malloc, calloc, realloc
- Memory deallocation with free
- Pointer usage with arrays and structs
- Indirect data reading and writing
- Calculating means and transformations using dynamically allocated vectors
- Memory-safe programming practices (null checks, zeroing memory, invalidating pointers)
## Problems
### Part 1 – Dynamic Allocation and Pointer Arithmetic
#### Problem 1.1 – Daily Temperature Processing
- Read minimum and maximum temperatures for n days using dynamically allocated arrays
- Compute the daily average temperatures and their overall mean
- Functions:
  - pcitireVector2(int n)
  - pafisareVectorIntregi(int *a, int n)
  - pafisareVectorReali(double *a, int n)
  - vectorMedie(int a, int b, int n)
  - mediaAritmeticaVector(double *a, int n)
  - mediaAritmeticaIntregi(int a, int b)
  - sumaVectorReali(double *a, int n)
#### Problem 1.2 – Cell Culture Growth Analysis
- Track the number of cells over n days
- Compute daily growth ratios and their geometric mean
- Indirect reading using dynamic memory
- Functions:
  - pcitireVectorInt(NATURAL *a, int n)
  - pafisareVectorInt(NATURAL *a, int n)
  - Functions for:
    - calculating the daily rate changes
    - printing a vector of doubles with 3 decimals
    - computing geometric mean
#### Problem 1.3 – Sum of Digits Vector
- Read vector of integers dynamically
- Create a second vector with each element as the sum of digits of the original element
- Identify the number with the maximum digit sum
- Functions:
  - Vector input/output
  - Digit sum calculation
  - Maximum index finding
### Part 2 – Operations on Sets with Dynamic Memory
#### Problem 2.1 – Vector Norms
- Read a vector of double values
- Calculate and display the:
  - Infinity norm (‖x‖∞)
  - L1 norm (‖x‖₁)
  - L2 norm (‖x‖₂)
- Vector operations performed via dynamically allocated memory
#### Problem 2.2 – Set Operations: Union, Intersection, Symmetric Difference
- Input two sets of doubles via dynamic memory
- Display sets and perform operations based on user menu:
  - Intersection
  - Symmetric Difference
  - Union
- Reusable functions from Problem 2.1 for input/output
- Includes:
  - Membership check
  - Menu display
  - Set operation functions returning new allocated sets
### Part 3 – Integer to ASCII Conversion
#### Problem 3.1 – Manual Integer to String Conversion
- Read an integer and dynamically allocate a string to store its ASCII representation
- Implement custom number-to-string conversion (no library functions)
- Display result as string
- Function:
  - char *transformareToAscii(long int)
## Build Instructions
To compile and link programs using dynamic memory:
```bash
clang -Wall -c vectorUtils.c      # Utility functions for vector operations
clang -Wall -c main.c             # Main program
clang vectorUtils.o main.o -o output

# Build with Makefile
- To build the project:
```bash
make
```
- To clean up build files:
```bash
make clean
```
