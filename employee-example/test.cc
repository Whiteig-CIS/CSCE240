// Copyright 2025 CSCE240
// test functionality of Employee class
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"employee.h"
#include"salaried.h"
#include"hourly.h"

using namespace CSCE240_Employees;

double Taxes(Employee& e, double tax_rate) {
  return e.Pay() * tax_rate;
}

int main() {

HourlyEmployee h("Bob", "Roberts", "Programmer", 12, 50, 40);
SalariedEmployee s("Sue", "Susan", "CEO", 12, 2000000);

cout <<"hourly employee" << h << " Salary Employee" << s << endl;
cout << "Taxes on " << h.Pay() << " = " << Taxes(h,0.3) << endl;
cout << "Taxes on " << s.Pay() << " = " << Taxes(s,0.3) << endl;





  /*
  Employee* ptr;
  char which;
  cout << "Are you an (h)ourly employee or a (s)alary?";
  cin >> which;
  if ( which == 'h' )
    ptr = new HourlyEmployee();
  else
    ptr = new SalariedEmployee();

    ptr -> Print();
    cout << "Pay = $" << ptr -> Pay() << endl;
    */
  return 0;
}
