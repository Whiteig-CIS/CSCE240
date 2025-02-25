// copyright 2025 Isaac White
#include "ArrayFunctions.h"
#include<cstdlib>
#include<ctime>

int main() {
    srand(time(0));
    const int kSize = 2000;
    int my_array[kSize] = {183, -1839, 21983, -2840};
    Populate(my_array, kSize);
   // PrintArray(my_array, kSize);
    InsertionSort(my_array, kSize);
   // PrintArray(my_array, kSize);
   InsertionSort(my_array, kSize);
    return 0;
}