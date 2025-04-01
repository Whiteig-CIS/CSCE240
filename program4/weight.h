//  Copyright Isaac WHite 2025
#ifndef _WEIGHT_H_
#define _WEIGHT_H_
#include<ostream>
#include<string>
using std::ostream;
using std::string;

// Define a Weight class that has private integer data members for the
//    weight value - a non-negative real number (a double)
//    weight units - allow for pounds, ounces, kilograms, and grams only
//                   (a string)
// The class should ensure that the data members always remain in a consistent
// state.
class Weight {
 private:
  string units_;
  double value_;

 public:
  // Add a constructor to allow the user to initialize the value and units, in
  // that order, with default arguments of 0 and "pounds"
  // If the first argument value is invalid, the weight value should be
  // initialized to 0. If the second argument is invalid, the weight units
  // should be initialized to pound.
  explicit Weight(double value = 0, string unit = "pounds");

  // Add mutator functions SetValue, and SetUnits that set the data member if
  // the argument is valid, and leave the data member unchanged if the argument
  // is invalid.
  Weight& SetValue(double weight);
  Weight& SetUnits(string unit);

  // Add accessor functions GetValue and GetUnits that return
  // a copy of the value of the corresponding data member.
  double GetValue() const { return value_; }
  string GetUnits() const { return units_; }

  // Add a ConvertUnits function that takes a string parameter for units to
  // convert the Weight to. If the argument is valid, the object's value and
  // units should be updated to the equivalent weight in the new units. For
  // example, if the Weight object w has a value of 2 and units of "pounds"
  // then after the function call w.ConvertUnits("ounces"); w should have a
  // value of 32 and units of "ounces"
  // If the argument sent to the function is not "pounds" "ounces" "kilograms"
  // or "grams" then the function should leave the object unchanged.
  // Please see testweight2.cc for more examples.
  void ConvertUnits(string new_unit);

  // note: you are welcome to add any additional member functions you would
  //       like

  // overload the <= operator to return true if the Weight on the left is
  // less than or equal to the Weight on the right, and false otherwise
  bool operator <= (Weight right) const;

  bool operator >= (Weight right) const;

  bool operator < (Weight right) const;

  bool operator > (Weight right) const;

  // overload the stream insertion operator to display the Weight in the format:
  // value units
  // with a single space between the value and units.
  friend ostream& operator << (std::ostream& os, const Weight& w);
};
  // note: you are welcome to overload any other operators you would like

#endif
