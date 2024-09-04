// Parameterised constructor and Default Constructor in C++

#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int, int);
    void printnumber(void)
    {
        cout << "Your complex number is :" << a << "+" << b << "i" << endl;
    }
};

Complex ::Complex(int x, int y)
{ //---->This is a parameterised constructer as it accepts parameters
    a = x, b = y;
    // cout<<"hello world";
}

int main()
{
    // Implicit call //
    Complex a(3, 4);
    a.printnumber();

    // Explicit call  //explicit means direct, clear
    Complex b = Complex(5, 7);
    b.printnumber();
    return 0;
}