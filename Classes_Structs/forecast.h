

#ifndef _FORECAST_H_
#define _FORECAST_H_

#include"temperature.h"

class Forecast {
 public:
  explicit Forecast( const Temperature& low = Temperature(40), const Temperature& high = Temperature(70) ); 
 private:
  Temperature low_;
  Temperature high_;

};

#endif