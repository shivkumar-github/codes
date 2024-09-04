// Pointer to objects and arrow operator in C++
#include <iostream>
using namespace std;

class Complex
{
    float real, imaginary;

public:
    void setdata(float a, float b)
    {
        real = a;
        imaginary = b;
    }
    void getdata(void)
    {
        cout << "The value of real part is : " << real << endl;
        cout << "The value of imaginary part is : " << imaginary << endl;
    }
};

int main()
{
    Complex c1;
    // Complex* ptr = &c1 ; can be also done by
    Complex *ptr = new Complex;

    // c1.setdata(1,54); This also can be written as
    //  (*ptr).setdata(1,54); // The braces are necessary // Can also be written as
    ptr->setdata(1, 54);
    // c1.getdata(); This also can be written as
    //  (*ptr).getdata(); This also can be written as
    ptr->getdata();

    Complex *ptr1 = new Complex[4];
    (ptr1 + 1)->setdata(1, 8);
    (ptr1 + 1)->getdata();
    return 0;
}