#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*struct Temperature {
//public: // members of a struct are public by default
  double value;
  string unit;
}; // semi-colon on end because we're defining it
*/

class Temperature {
 public:
Temperature(){
    cout << "constructor" << endl;
    value_ = 70;
    unit_ = "Fahrenheit";
}
 private:
  double value_; // Google style guide - end private members with trailing underscore
  string unit_;
};

int main() {
    Temperature t; // declares a variable of structure type
    t.value = 60; // use dot operator to directly access public memberds
    t.unit = "Fahrenheit";
    cout << t.value << " " << t.unit << endl;

    Temperature* tptr = &t;
    cout << "using tptr to access the value: " << (*tptr).value << endl;
    // can use the arrow operator on a pointer to access the public members
    cout << "using tptr to access the value: " << tptr->value << endl;

    return 0;
}