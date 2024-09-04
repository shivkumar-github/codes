// Classes, Public and Private access modifiers in C++

// data in structures is not secure as data can be accesed from anywhere
// if we want to add data as well as functions with increase in security

#include <iostream>
using namespace std;

// Forward declaration of class
// class employee;  //no curly braces

class employee
{        // In class members are private by default
         // and in struct members are public by default
         //  functions in classes also called as members or member functions
         //   public and private are called access modifiers
private: // data in private can be accessed by function in that class only
    int a, b, c;

public:
    int d, e; // this can be accesed from any where

    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
    void setData(int a1, int b1, int c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }

    // functions in classes also can be defined outside the class as

    /*void employee::setData(int a1, int b1, int c1)
    { // telling the complier that is from class employee
        a = a1;
        b = b1;
        c = c1;
    }
    */

}; // as classes are user defined data types we need to use semicolon after declaration
// objects also can be defined by writing object name after curly braces which end the class
//  for ex. class a{} harry, dev , rohandas ; //but this practise is not recommended.

int main()
{
    employee harry; // harry is object
    // harry.a=88; -->this will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1, 2, 4);
    harry.getData();
    return 0;
}