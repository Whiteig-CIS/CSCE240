#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
// #include"temperature.h"
#include"forecast.h"

/*/ using namespace temp;      // either works
using temp::Temperature;
//  we can send the object as a reference parameter or value parameter
//  Value param makes a copy (calls constructor and destructor).
//  Ref param sends a ref to the object calling the func.
//  additionally, adding "const" qual, ensures saftey of the objects data
void IsItHot(const Temperature& t) {
    if ( (t.getValue() >= 80 && t.getUnit() == "Fahrenheit") ||
             (t.getValue() >= 26.667 && t.getUnit() == "Celsius") ||
             (t.getValue() >= 299.82 && t.getUnit() == "Kelvin") )
             cout << "It's hot" << endl;
}



int main() {

  Temperature::DisplayAsAbbreviation(false);
  Temperature t(32); // automatically calls the constructor (intantiating)
  cout << t << endl;
  t.setUnit("Celsius").setValue(0);
  cout << t << endl;
   IsItHot(t);

   t.ConvertUnit("Kelvin");
   cout << t << endl;
   t.ConvertUnit("Fahrenheit");
   cout << t << endl;
   t.ConvertUnit("Celsius");
   cout << t << endl;
// IsItHot(80); // this implicitley casted the int to a Temperature 
               // by calling the constructor of Tempurature
 // IsItHot(static_cast<Temperature>(80));

 // cout << ++t << endl;
Temperature t2(32);

t.DisplayAsAbbreviation(true);
if ( t == t2 ) // overloaded ==
  cout << t << " == " << t2 << endl; 
  return 0;
} */

int main() {

    Forecast f;
    cout << f.low_ << " " << f.high_ << endl;

    return 0;
}