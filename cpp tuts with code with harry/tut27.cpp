// Friend Classes & Member Functions in C++

#include <iostream>
using namespace std;

// Forward Declaration
class Complex;

class Calculator
{
public:
    int sumRealp(Complex o1, Complex o2);
    int sumImgp(Complex o1, Complex o2);
};

class Complex
{
    int realp, imgp;
    // // Individually declaring functions as friends if we want to give access to only some functions
    // friend int Calculator ::sumRealp(Complex, Complex);
    // friend int Calculator ::sumImgp(Complex, Complex);

    // Alternate way : Dclaring the whole class as friend if we want to give access of data to all functions
    friend class Calculator;

public:
    void setNumber(int realp1, int imgp1)
    {
        realp = realp1;
        imgp = imgp1;
    }

    void printNumber()
    {
        cout << "Your complex number is :" << realp << "+" << imgp << "i" << endl;
    }
};

// the definations of member functions of functions accessing data from a class should be kept after the defination of the class
// if not kept then while compiling the code it first sees the functions trying to access the data of class complex, but that data is not currently defined hence gives error
int Calculator ::sumRealp(Complex o1, Complex o2)
{
    return o1.realp + o2.realp;
}

int Calculator ::sumImgp(Complex o1, Complex o2)
{
    return o1.imgp + o2.imgp;
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);

    Calculator calc;

    cout << "The sum of real part of o1 and o2 is :" << calc.sumRealp(o1, o2) << endl;
    cout << "The sum of imagenary part of o1 and o2 is :" << calc.sumImgp(o1, o2) << endl;
    return 0;
}