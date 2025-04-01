//  Copyright Isaac White 2025

#include<string>
#include"weightrange.h"
using std::string;
using std::ostream;

//  default constructor
WeightRange::WeightRange() : smallest_(Weight(0)), largest_(0) {}

//  constructor
//  - Initializes the smallest_ and largest_ to 0 pounds
WeightRange::WeightRange(const Weight& w1, const Weight& w2) {
  if ( w1 <= w2 ) {
    smallest_ = w1;
    largest_ = w2;
  } else {
      smallest_ = w2;
      largest_ = w1;
  }
}

//  - Checks if the parameter Weight is valid and if so, sets smallest_ to the
//    smallest of the two Weights and largest_ to the largest of the two.
void WeightRange::SetSmallest(const Weight& w) {
  if ( w <= smallest_ )
    smallest_ = w;
}

//  - Checks if the parameter Weight is valid and if so, sets largest_ to the
//    largest of the two Weights and smallest_ to the smallest of the two.
//    If the parameter is not valid, smallest_ remains unchanged.
void WeightRange::SetLargest(const Weight& w) {
  if ( largest_ <= w)
    largest_ = w;
}

// - Determines whether or not the parameter Weight is in the range of
//   smallest_ and largest_. The inclusive parameter determines whether or not
//   the smallest_ and largest_ are endpoints in the range.
bool WeightRange::InRange(const Weight& w, bool inclusive) {
  if ( inclusive ) {
    return ( (w >= smallest_) && (w <= largest_) );
  } else if ( !inclusive ) {
      return ( (w > smallest_) && (w < largest_));
  } else {
    return false;
  }
}

// - Determines the width of the range by subtracting the smallest_ from
//   largest_. The width is returned in the units of the largest_ as a
//   Weight object.
Weight WeightRange::Width() {
  Weight smallest = smallest_;
  smallest.ConvertUnits(largest_.GetUnits());
  return Weight((largest_.GetValue() - smallest.GetValue()),
                (largest_.GetUnits()));
}

//  - Overload the << operator to print the WeightRange object in the
//    format smallest_ - largest_.
ostream& operator << (std::ostream& os, const WeightRange& w) {
  os << w.smallest_ << " - " << w.largest_;
  return os;
}
