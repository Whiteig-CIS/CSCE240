#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

 /* //-- EXAMPLE OF DELETE OPERATOR --//

// scenario: ask the user to enter all of their grades and hold them in memory
// to perform statistical analysis, etc.

int current_size = 5; // keeps track of how much size we have
int* the_grades = new int[current_size]; // this pointer holds the grades and reserves 5 ints to hold them in
int grade, i = 0;
cout << "Enter your grades (input -1 to quit) ";

cin >> grade;
while ( grade != -1 ) {   
  if ( i == current_size ){
    int* temp = the_grades; // keep track of old values because the next line overrides them.
    the_grades = new int[2 * current_size]; // reserve new block of memory
    // copy over the old values into the new block
    for ( int j = 0; j < current_size; j++)
      the_grades[j] = temp[j];
    // free up the old block
    delete [] temp; // if we forget this line, the program will run but the data
                    // stored in temp wont be freed up so it will be stored for no reason which is inefficient.
  }
  the_grades[i] = grade;
  ++i;                    
  cin >> grade;
}
for(int k = 0; k < current_size; ++k)
  cout << the_grades[k] << endl;
return 0; */



/* //-- EXAMPLE OF POINTER ARRAY--// 

  // all these values are fixed, space has been wasted 
  // char likert[5][27] 

  //  This is how you would use an array of pointers, it is more efficient.
 const char * likert[5] = {"strongly agree", "agree",            
                         "neither agree nor disagree", "disagree",  
                        "strongly disagree"};

  
  for ( int i = 0; i < 5; ++i)
    cout << likert[i] << endl;
  return 0; */

   /* //--EXAMPLE OF POINTERS AND MEMORY LEAKS--//
  int size = 100000;
  double* num = new double[size];
  char again = 'y';
  while ( again == 'y' ) {
    ++size;
    delete [] num; // plugs the memory leak
    num = new double[size];
    for( int i = 0; i < size; ++i ) 
      num[i] = 1;
      cout << "Current size is " << size << ". Need more?";
      cin >> again;
    
  }
  return 0;*/

}