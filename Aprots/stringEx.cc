// copyright Isaac White 2025

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

// -- g++ -std=c++17 -Wall stringEx.cc -o string 
// -- g++ -std=c++17 -Wall -c stringEx.cc

//  this creates a class called exclamation that is a chile of the string class
class Exclamation : public string {
 public:
  Exclamation(const string& s) : string(s) {
    if ( s[s.length() -1] == '.' || s[s.length() -1] == '?' )
      operator[] (s.length() - 1) = '!';  // this is the same as doing e[s.length - 1] = '!';
    else if ( s[s.length() -1] != '!' )
      *this += '!';
  }

};

int main() {
  Exclamation e("Hello World.");
  cout << e << endl;
  cout << e.length() << endl;
  cout << "the first character in the string is " << e[0];


}

