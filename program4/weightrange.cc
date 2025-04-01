//  Copyright Isaac White 2025

#include<string>
#include"weightrange.h"
using std::string;
using std::ostream;

//  default constructor
WeightRange::WeightRange() : smallest_(Weight(0)), largest_(0) {}

WeightRange::WeightRange(const Weight& w1, const Weight& w2) {
  if ( w1 <= w2 ) {
    smallest_ = w1;
    largest_ = w2;
  } else {
      smallest_ = w2;
      largest_ = w1;
  }
}

void WeightRange::SetSmallest(const Weight& w) {
  if ( w <= smallest_ )
    smallest_ = w;
}

void WeightRange::SetLargest(const Weight& w) {
  if ( largest_ <= w)
    largest_ = w;
}

bool WeightRange::InRange(const Weight& w, bool inclusive) {
  if ( inclusive ) {
    return ( (w >= smallest_) && (w <= largest_) );
  } else if ( !inclusive ) {
      return ( (w > smallest_) && (w < largest_));
  } else {
    return false;
  }
}

Weight WeightRange::Width() {
  Weight smallest = smallest_;
  smallest.ConvertUnits(largest_.GetUnits());
  return Weight((largest_.GetValue() - smallest.GetValue()),
                (largest_.GetUnits()));
}

ostream& operator << (std::ostream& os, const WeightRange& w) {
  os << w.smallest_ << " - " << w.largest_;
  return os;
}
