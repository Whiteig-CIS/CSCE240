

#include"forecast.h"
#include"temperature.h"

//  when we have objects as data members, using the member initializer list
//  allows us to call the constructor for the data members in the way that we want.(not using the default constructors and then assigning.)
Forecast::Forecast(const Temperature& low, const Temperature& high) : low_(low), high_(high){
 // low_ = low;
 // high_ = high;

}