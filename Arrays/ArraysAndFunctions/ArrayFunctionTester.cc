// copyright 2025 Isaac White
#include "ArrayFunctions.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
int main() {
 
 char my_cstring[6] ="abcde"; // = {'a', 'b', 'c', 'd', 'e'};
 for (int i = 0; i < 5; ++i) 
    cout << my_cstring[i];
 cout << endl;

 //my_cstring[5] = 'f'; //makes string to large and doesnt have room for a null character at the end of the array

 int i = 0;
 while (my_cstring[i] != '\0' ) 
   cout << my_cstring[i++];
 cout << endl;

 cout << my_cstring << endl;

 cout << "enter a new cstring ";
 //cin >> my_cstring; // reads up until whitespace 

 cin.getline(my_cstring, 6, ' '); // this is a different way to take user input 
                             // it doesnt stop at whitespace and will cut the string down
                             //to one less chars than the second int parameter
                             //you can add a third parameter that will tell it to stop writing in at that character
 cout << "Here is what I got: " << my_cstring << endl;
 
 
 char sentence[] = "hi my names iggy";

 CapitolizeTheWords(sentence);
 cout << sentence << endl;
 return 0;
 
 
 
 
 
    /*
 const int kNumRows = 4;
 int sums[kCols] = {};
 int numbers[kNumRows][kCols] = { {1,2}, {2, 3, 4}, {5}};
 PrintArray(numbers, kNumRows, 4);
 ColumnSums(numbers, kNumRows, sums);
 */
 
 
 
 
 
    /*   srand(time(0));
    const int kSize = 2000;
    int my_array[kSize] = {183, -1839, 21983, -2840};
    Populate(my_array, kSize);
   // PrintArray(my_array, kSize);
    InsertionSort(my_array, kSize);
   // PrintArray(my_array, kSize);
   InsertionSort(my_array, kSize);
    return 0;  
    */
}