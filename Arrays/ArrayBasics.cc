// copyright 2025 Isaac White
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
  const int kNumPrograms = 6; // how to define a constant 
//double program_grades[kNumPrograms];                                //-------OPTION 1---------//
    
//double program_grades[6];                                           //-------OPTION 2---------//
    
  double program_grades[] = { 100, 90.6, 64.3, 38.8, 95.2, 77.3 };    //-------OPTION 3---------// 
  int num[3] = {1,5,-9};
  /*for( int i = 0; i < kNumPrograms; i++ ){ // taking user input for array elements
    cout << "enter a double value for the array at index : " << i << endl;
    cin >> program_grades[i];
  } */
    
  for( int i = 0; i < kNumPrograms; ++i ) //outputting values
    cout << "grade at index: " << i << " = " << program_grades[i] << endl;

    cout << "outputting the amount of bytes of an int" << sizeof(int) << endl;
    cout << "outputting the amount of bytes of an double" << sizeof(double) << endl;

    cout << "memory address for the array: "<< program_grades << endl;
    cout << "adding 1 (8bytes) to the memory address ..." << endl;
   cout << "displaying memory address for the array plus 1: " << program_grades + 1 << endl;
return 0;
}