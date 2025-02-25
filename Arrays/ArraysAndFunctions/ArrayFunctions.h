// copright 2025 Isaac White
#ifndef _ARRAY_FUNCTIONS_H_
#define _ARRAY_FUNCTIONS_H_

// function that capitolizes the first char in each word
// in a cstring that holds a sentence.
// pre-condition: the argument is a valid cstring with a terminating character
void CapitolizeTheWords(char sentence[]);

const int kCols = 8; // this constant can be used by any file that

// compute column sum of multidimensional array
void ColumnSums(const int [][kCols], int num_rows, int sums[kCols]);

                                                    // arrayfunctions.h
// print a multidimensional array of integers
void PrintArray(const int[][kCols] , int num_rows, int field_width = 0);

// inertion sort - worst case and average case is o(n^2) but best case is o(n)
// idea: build a largwer and largwer sorted list by inserting a new value each time
void InsertionSort(int[], int size);

// populate an array with the "random" integers
void Populate(int[], int size, int min = 0, int max = 100);

// Arrays as function parameters - type []
void PrintArray(const int [], int size, int feild_width = 0);

// linear search - start at one end and, move element by element until you fing the search value or run out of elemnts
int LinearSearch(const int [], int size, int target);

#endif