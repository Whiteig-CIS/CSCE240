// copyright 2025 Isaac White
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

// arrays as fuction parameters

//prototype
//void PrintArray(int [], int); // this version of the function allows the function to modify the values of the array
  void PrintArray(const int [], int); // this version does not allow the function to modify the values of the array
                                     // keep in mind that with this prototype, the implementation must also have 
                                     //"const" before the first parameter

// linear search: start at one end and move element to element until you find it or run out of null
int LinearSearch(const int [], int size, int target);

int main(){
  const int kSize = 10;
  int numbers[kSize] = {12, 123, -4583};
  // sending the address of the array to the function as the first parameter
  PrintArray(numbers, kSize);
  //cout << "printing the arrays after the PrintArray function has modified them" << endl;
  //PrintArray(numbers, kSize);

  cout << "what are you looking for? ";
  int s;
  cin >> s;
  cout << LinearSearch(numbers, kSize, s) << endl;
  return 0;
}

void PrintArray(const int a[], int n){
  for ( int i = 0; i < n; ++i)
    cout << a[i] << " "; // since the first parameter of the function is an address, the function CAN MODIFY the arrays values
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