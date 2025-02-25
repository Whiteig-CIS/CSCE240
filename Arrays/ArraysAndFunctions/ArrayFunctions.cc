// copyright 2025 Isaac White
#include"ArrayFunctions.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::swap;
#include<iomanip> // has cout, cin, and endl
#include<cmath> // has the log function
#include<cstdlib> // has ran function or randomizer


void  InsertionSort(int a[], int size){
    int start = clock();
    for ( int sorted = 1; sorted < size; ++sorted) {
      int i = sorted;
      while ( i > 0 && a[i] < a[i - 1] ) {
        swap(a[i], a[i-1]);
        --i;
      }
    }
    cout << clock() - start << endl;
}

void PrintArray(const int a[], int n, int feildWidth){
    if(  feildWidth == 0 ) { // if user didnt specify a feild width ie it is it's default value 0,
                             // than go into this if statement to determine what the spacing should be
        int maxDigits = 1, digits;
        for ( int i = 0; i < n; ++i ) {
          if ( a[i] != 0 ) {
            digits = log10(abs(a[i])) + 1;
            if ( a[i] < 0 ) 
              ++digits; // account for negative sign
            if ( digits > maxDigits )
              maxDigits = digits;
          }
        }
        feildWidth = maxDigits + 2;
    }
    for ( int i = 0; i < n; ++i)
      cout << std::setw(feildWidth) << a[i]; // since the first parameter of the function is an address, the function CAN MODIFY the arrays values
      cout << endl;
  }
  
  int LinearSearch(const int a[], int size, int target){
    int target_position = -1, i = 0;
    while ( i < size && target_position == -1){
      if ( a[i] == target )
        target_position = i; 
        i++;
    }
    return target_position;
  }

  void Populate(int a[], int size, int min, int max){
if ( min > max ) 
  swap(min, max);
  for ( int i = 0; i < size; ++i ) {
    a[i] = rand() % (max - min +1) + min;
  }
  }
