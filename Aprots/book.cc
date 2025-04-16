// copyright Isaac White 2025
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include"book.h"
// -- g++ -std=c++17 -Wall book.cc -o string 
// -- g++ -std=c++17 -Wall -c book.cc

namespace bookEx {

Book::Book() {
    title_ = "Green Eggs and Ham";
    author_ = "Dr.Suess";
    pub_year_ = 1960;

}

Book& Book::operator = (const Book& tocopy) {  // return type: Book& // method location: Book // name: operator = // parameters // Book& tocopy
  title_ = tocopy.title_;
  author_ = tocopy.author_;
  pub_year_ = tocopy.pub_year_;
  return *this;

}

void Book::Print() const {
    
}

} // end bookEx namespace