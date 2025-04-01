#ifndef _TEMPERATURE_
#define _TEMPERATURE_
#include<string>
#include<iostream>
#include<ostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;


// note: in c++ the file doesn't have to match the class name
class Temperature {

  friend ostream& operator << (std::ostream& os, const Temperature& t);

 public: // - One space indent in the class definition for public/private/protected


//  ++x;
Temperature& operator ++() { ++value_; return *this; };
 
//  x++;
Temperature operator ++(int){
 Temperature copy(*this);
 ++value_;
 return copy;
}


 // the "explicit" makes it so the constructor can only be called if specifically asked.
 // Only needs to be marked in the header file.
 explicit Temperature(double value = 60, string unit = "Fahrenheit");

 // DESTRUCTOR - special function called when memory 
 //              for an object is released
 //              no return type, name = ~Classname, NO parameters
 ~Temperature();  // can't be overloaded

// - accessor functions
// - the const qualifier makes it so the function wont 
//   modify the instance vairables .
  string getUnit() const { return unit_; }
  int getValue() const { return value_; }

// mutator functions
  Temperature& setUnit(string unit); // returns a reference of a Temperature
  bool setValue(double value);

  void ConvertUnit(string new_unit);

  //  - Overloading the == operator, it can be a member because the left hnd side is a Temperature
  //  - The left hand Obj calls the operator and the right Obj is the param
  //  - The const in the param is for the right Obj and the const outside the parenthesis is for the left Obj
  //  - "x == y" is the same as "x.operator ==(y);"
  bool operator == ( Temperature right) const; 

  static void DisplayAsAbbreviation(bool a);

 private:
  double value_; // Google style guide - end private members with trailing underscore
  string unit_;
     // unit_ is an object of the string class
     // using objects of one class as data members in another class is called composition.

     static bool abbrev_;
   };

#endif