#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//  g++ -std=c++17 -Wall    


class A {
 public: 
  A() { cout << "A() called." << endl; }



  ~A() {
  cout << "A~() called" << endl;
  }
  int GetA() const { return anum_; }

  protected:
    int aprot_;
    void Aprot() { cout << "Aprot() call" << endl; }

  private:
   int anum_;
   void Apriv() { cout << "Apriv() call " << endl;}
};

  class B : public A { 
    public:
    B() {
        cout << "B() called " << endl;
    }
    ~B() {
        cout << "~B() called " << endl;
    }

    //  redifining the function GetA() withthe same name and parameter list
    int GetA() const {
        cout << "In B's version of the GetA class" << endl;
        // Calling the GetA() method from the parent class
        return A::GetA();
    }
  };

  int main () {
    B bobject;
    cout << bobject.GetA() << endl;
    return 0;
  }