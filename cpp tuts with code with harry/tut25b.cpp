// Passing objects as function arguements
// this program prints sum of two complex numbers

#include <iostream>
using namespace std;

class complex
{              // it is a good practice to keep data members private
    int realp; // represents real part of a complex number
    int imgp;  // represents imagenary part of a complex number
    int timgp;
    int trealp;

public:
    void setData(int realp1, int imgp1)
    { // imgp1 and realp1 are used to get values in functions
        realp = realp1;
        imgp = imgp1;
    }

    void setDatabysum(complex o1, complex o2)
    {
        trealp = o1.realp + o2.realp; // adding real parts of two comlex number to do their addition
        timgp = o1.imgp + o2.imgp;    // adding imaginary parts of two comlex number to do their addition
    }

    void printfinalcomplexno()
    {
        cout << "The addition of two complex numbers is :" << trealp << "+" << timgp << "i" << endl;
    }
};

int main()
{
    complex c1, c2, c3;

    c1.setData(1, 2);
    c2.setData(3, 4);

    c3.setDatabysum(c1, c2);
    c3.printfinalcomplexno();

    return 0;
}