// Copyright Isaac White 2025

#include"weight.h"
#include<string>
using std::string;
using std::ostream;

Weight::Weight(double value, string unit) : value_(0), units_("pounds") {
  SetValue(value).SetUnits(unit);
}

//  mutator functions

Weight& Weight::SetValue(double weight) {
  if ( weight >= 0)
    value_ = weight;
  return *this;  //  dereferencing the "this" pointer.
}

Weight& Weight::SetUnits(string unit) {
  if ( (unit == "pounds" || unit == "kilograms" ||
        unit == "ounces" || unit == "grams") )
    units_ = unit;
  return *this;
}

// convert units function.
// verify that parameter is valid and if so, convert value to desired unit.
void Weight::ConvertUnits(const string new_unit) {
  if ( units_ == "pounds" ) {
    if ( new_unit == "kilograms" ) {
      value_ = value_ * 0.453592;
      units_ = "kilograms";
    } else if ( new_unit == "ounces" ) {
        value_ = value_ * 16.0;
        units_ = "ounces";
    } else if ( (new_unit == "grams") ) {
        value_ = value_ * 453.592;
        units_ = "grams";
    }
  } else if ( units_ == "kilograms" ) {
    if ( new_unit == "pounds" ) {
      value_ = value_ / 0.453592;;
      units_ = "pounds";
    } else if ( new_unit == "ounces" ) {
        value_ = value_ * 35.374;
        units_ = "ounces";
    } else if ( (new_unit == "grams") ) {
        value_ = value_ * 1000;
        units_ = "grams";
    }
  } else if ( units_ == "ounces" ) {
    if ( new_unit == "pounds" ) {
      value_ = value_ / 16.0;
      units_ = "pounds";
    } else if ( new_unit == "kilogram" ) {
        value_ = value_ / 35.374;
        units_ = "kilogram";
    } else if ( (new_unit == "grams") ) {
        value_ = value_ * 28.3495;
        units_ = "grams";
    }
  } else if ( units_ == "grams" ) {
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

bool Weight::operator >= (Weight right) const {
    right.ConvertUnits(units_);  // converts the right to the unit of the left
    return value_ >= right.value_;
  }
  bool Weight::operator < (Weight right) const {
    right.ConvertUnits(units_);  // converts the right to the unit of the left
    return value_ < right.value_;
  }
  bool Weight::operator > (Weight right) const {
    right.ConvertUnits(units_);  // converts the right to the unit of the left
    return value_ > right.value_;
  }

ostream& operator << (std::ostream& os, const Weight& w) {
    os << w.value_ << " " << w.units_;
    return os;
}


