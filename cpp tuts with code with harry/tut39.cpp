// Protected Access Modifiers in C++

#include <iostream>
using namespace std;

class Base
{
protected: // private jaise par inherit ho sakta hai
    int a;

private:
    int b;
};
/*
For a protected member :
                                     Public derivation         Private derivation         Protected derivation
1. Private members of base class     Not inherited             Not inherited              Not inherited
2. Protected members of base class   Protected                 Private                    Protected
3. Public members of base class      Public                    Private                    Protected

*/
class Derived : protected Base
{
};
int main()
{
    Base b;
    Derived d;
    // d.a;  both will give errors as a is protected in both Derived and Base class and  hence can not be accessed directly from out of the class
    // b.a;
    return 0;
}