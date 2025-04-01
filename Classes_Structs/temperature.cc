#include"temperature.h"
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

                                                    // member initializer list for constructor
                                                    // allows non-static data members to be initialized
                                                    // before the body of the constructor executes
Temperature::Temperature(double value, string unit) : value_(70), unit_("Fahrenheit"){ // the "Temperature::" part tells the compiler that 
    setUnit(unit);
    setValue(value);
}

//  static data members are initialized for the class
bool Temperature::abbrev_ = true;

void Temperature::DisplayAsAbbreviation(bool a) {
  abbrev_ = a;
}

//  not a member
ostream& operator << (std::ostream& os, const Temperature& temp) {
    os << "Temperature: " << temp.value_ << (temp.unit_ == "Kelvin" ? " " : " \u00B0") ;
    if ( temp.abbrev_)
      cout << temp.unit_[0];
    else 
      cout << temp.unit_;
    return os;
}

//  member
bool Temperature::operator == (Temperature right) const {
 // return value_ == right.value_ && unit_ == right.unit_;
 right.ConvertUnit(unit_); // converts the right to the unit of the left
 return value_ == right.value_; 
}

void Temperature::ConvertUnit(string new_unit){
  if ( unit_ == "Fahrenheit" ) {
    if ( new_unit == "Celsius" ) {
        unit_ = "Celsius";
        value_ = (value_ - 32) * (5.0 / 9);
    } else if ( new_unit == "Kelvin" ) {
        unit_ = "Kelvin";
        value_ = (value_ - 32) * (5.0 / 9) + 273.15;
    }
  } else if ( unit_ == "Celsius" ) {
    if ( new_unit == "Fahrenheit" ) {
        unit_ = "Fahrenheit";
        value_ = value_  * (9.0 / 5) + 32;
    } else if ( new_unit == "Kelvin" ) {
        unit_ = "Kelvin";
        value_ = value_ + 273.15;
    }
  } else if ( unit_ == "Kelvin" ) {
    if ( new_unit == "Fahrenheit" ) {
        unit_ = "Fahrenheit";
        value_ = (value_  - 273.15) * (9.0 / 5) + 32;
    } else if ( new_unit == "Celsius" ) {
        unit_ = "Celsius";
        value_ = value_ - 273.15;
    }
  }

}


// note: make sure that the unit is only changed if temp value is valid
Temperature& Temperature::setUnit(string unit) {
  if ( unit == "Fahrenheit" || unit == "Celsius" || unit == "Kelvin")
    unit_ = unit;
  return *this; // - "this" is a pointer to the object the function is called upon.
                // - The "*" de-references the pointer. Every non-static function
                //   has access to the "this" pointer.
}

bool Temperature::setValue(double value){ 
  if ( (unit_ == "Kelvin" && value_ >= 0) ||
       (unit_ == "Celsius" && value_ >= -273.15) ||
       (unit_ == "Fahrenheit" && value_ >= -459.67) )
    value_ = value;
  return value_ == value; // returns true if the value sent is the value_ after the operation
}

Temperature::~Temperature() {
    cout << "Destructor for " << value_ << " " << unit_ << " called." << endl;
}
