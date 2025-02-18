#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"program2functions.h"
#include"program2functions.cc"

int main(){
    if(DigitInPosition()){
        cout << "6 is perfect" << endl;
    }
    else{
        cout << "6 is not perfect" << endl;
    }
}