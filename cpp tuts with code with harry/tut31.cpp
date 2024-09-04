// Constructer Overloading in C++

#include <iostream>
using namespace std;

class Complex
{
    int realpart, imgpart;

public:
    Complex(int real, int img)
    {
        realpart = real;
        imgpart = img;
    }
    Complex(int real)
    {
        realpart = real;
        imgpart = 0;
    }
    Complex()
    {
        realpart = 0;
        imgpart = 0;
    }

    // The work done by these three constructers can be done by passing default arguements to the constructer
    // Complex(int real=0, int img=0){
    // realpart=real;
    // imgpart=img;
    // }

    void printComplex()
    {
        cout << "The Complex number is :  " << realpart << "+" << imgpart << "i" << endl;
    }
};

int main()
{
    Complex c1(4, 6);
    c1.printComplex();

    Complex c2(5);
    c2.printComplex();

    Complex c3;
    c3.printComplex();
    return 0;
}