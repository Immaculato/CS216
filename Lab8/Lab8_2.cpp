//course: CS216-00x
//Project: Lab Assignment 8
//program: Lab8_2.cpp
//Date: 03/17/2016
//Purpose: Use as the lab assignment example
//
//Author: (your name)

#include <iostream>
#include <string>
using namespace std;

//define our own exception class
class Matherr {
    public:
        Matherr() {this->errname = "Math Error.";}
        string getName() const {return this->errname;}
        void setName(string name) {this->errname = name;}
    private: 
        string errname; 
};

class DivideByZero : public Matherr
{
    public:
        DivideByZero() {setName("Division by zero");}
};
 
double divide(int a, int b) {
    if(b == 0)
        throw DivideByZero();
    return (double) a / b;
}
 
int main() {
    double d = 0; 
    try {
		d = divide(5, d);
                cout << d << endl;
    }
    catch (DivideByZero& err) {
        cout << "Exception: " << err.getName() << endl;
    }
    cout << "After try-catch block!" << endl;
    cout << "The value of d is: " << d << endl;
    return 0;
}
