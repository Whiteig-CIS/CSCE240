// Copyright Isaac White 2025

#include"weight.h"
#include<string>
using std::string;
using std::ostream;

//  default constructor
//  - Initializes the value_ to 0 and units_ to "pounds"
Weight::Weight(double value, string unit) : value_(0), units_("pounds") {
  SetValue(value).SetUnits(unit);
}

//  mutator functions
//  - Checks if the parameter Weight is >= 0 and if so,
//    sets value_ to the Weight.
Weight& Weight::SetValue(double weight) {
  if ( weight >= 0)
    value_ = weight;
  return *this;  //  dereferencing the "this" pointer.
}

//  - Checks if the parameter unit is valid and if so, sets units_ to the unit.
//    If the parameter is not valid, units_ remains unchanged.
//    Valid units are: pounds, ounces, kilograms, grams
Weight& Weight::SetUnits(string unit) {
  if ( (unit == "pounds" || unit == "kilograms" ||
        unit == "ounces" || unit == "grams") )
    units_ = unit;
  return *this;
}

// convert units function.
// verify that parameter is valid and if so, convert value to desired unit.
void Weight::ConvertUnits(const string new_unit) {
  if ( units_ == "pounds" ) {  // converts pounds to new_unit
    if ( new_unit == "kilograms" ) {
      value_ = value_ * 0.453592;
      units_ = "kilograms";
    } else if ( new_unit == "ounces" ) {
        value_ = value_ * 16.0;
        units_ = "ounces";
    } else if ( (new_unit == "grams") ) {
        value_ = value_ * 453.592375;
        units_ = "grams";
    }
  } else if ( units_ == "kilograms" ) {  // converts kilograms to new_unit
    if ( new_unit == "pounds" ) {
      value_ = value_ / 0.453592;;
      units_ = "pounds";
    } else if ( new_unit == "ounces" ) {
        value_ = value_ * 35.27396;
        units_ = "ounces";
    } else if ( (new_unit == "grams") ) {
        value_ = value_ * 1000;
        units_ = "grams";
    }
  } else if ( units_ == "ounces" ) {  // converts ounces to new_unit
    if ( new_unit == "pounds" ) {
      value_ = value_ / 16.0;
      units_ = "pounds";
    } else if ( new_unit == "kilograms" ) {
        value_ = value_ * 0.0283495231;
        units_ = "kilograms";
    } else if ( (new_unit == "grams") ) {
        value_ = value_ * 28.3495;
        units_ = "grams";
    }
  } else if ( units_ == "grams" ) {  // converts grams to new_unit
    if ( new_unit == "pounds" ) {
      value_ = value_ / 453.592;;
      units_ = "pounds";
    } else if ( new_unit == "ounces" ) {
        value_ = value_ / 28.3495;
        units_ = "ounces";
    } else if ( (new_unit == "kilograms") ) {
        value_ = value_ / 1000;
        units_ = "kilograms";
    }
  }
}

//  overriding the <= operator
//  this is a member of the class since the left hand side will be Weight
bool Weight::operator <= (Weight right) const {
  right.ConvertUnits(units_);  // converts the right to the unit of the left
  return value_ <= right.value_;
}

//  overriding the >= operator
//  this is a member of the class since the left hand side will be Weight
bool Weight::operator >= (Weight right) const {
  right.ConvertUnits(units_);  // converts the right to the unit of the left
  return value_ >= right.value_;
  }

//  overriding the < operator
//  this is a member of the class since the left hand side will be Weight
bool Weight::operator < (Weight right) const {
  right.ConvertUnits(units_);  // converts the right to the unit of the left
  return value_ < right.value_;
  }

//  overriding the > operator
//  this is a member of the class since the left hand side will be Weight
bool Weight::operator > (Weight right) const {
  right.ConvertUnits(units_);  // converts the right to the unit of the left
  return value_ > right.value_;
  }

//  Overriding the "<<" stream insertion operator
ostream& operator << (std::ostream& os, const Weight& w) {
  os << w.value_ << " " << w.units_;
  return os;
}


