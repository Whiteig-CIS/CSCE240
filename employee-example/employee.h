// Copyright 2025 CSCE240
// Define the Employee class
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include<iostream>
using std::ostream;
#include<string>
using std::string;

namespace CSCE240_Employees {

class Employee {
  friend ostream& operator << (ostream&, const Employee&);

 public:
  explicit Employee(string first = "Jane", string last = "Doe",
                     string job_title = "TBD", int ppy = 0);
  // all derived class destructors will be virtual
  virtual ~Employee() {}
  void SetFirst(string f);
  void SetLast(string l);
  void SetJobTitle(string title);
  void SetPaysPerYear(int);

  string GetFirst() const { return first_name_; }
  string GetLast() const { return last_name_; }
  string GetJobTitle() const { return job_title_; }
  int GetPaysPerYear() const { return pays_per_year_; }

  virtual void Print() const;



  // - making a  virtual function because it will be determined
  //   if salary or hourly pay methods will be used at runtime.

  // - Adding the "= 0" top the end makes it a "pure virtual" 
  //   meaning that the function isnt implemented in This class.

  // - This makes this class ABSTRACT which means it CANNOT me instantiated 
  //   directly, only the children classes can be instantiated

  // - interfaces are abstract classes with NO DATA MEMBERS
  virtual double Pay() const = 0;

 private:
  string first_name_;
  string last_name_;
  string job_title_;
  int pays_per_year_;
};  // end class Employee

}  // namespace CSCE240_Employees

#endif  // _EMPLOYEE_H_
