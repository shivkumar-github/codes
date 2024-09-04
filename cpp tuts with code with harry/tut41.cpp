// Multiple Inheritance Deep Dive with examples

#include <iostream>
using namespace std;
/*
class DerivedC: visibility_mode base1, visibility_mode base2
{
    class body of class "DerivedC"
};
*/

class Base1
{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};

class Base2
{
protected:
    int base2int;

public:
    void set_base2int(int a)
    {
        base2int = a;
    }
};

class Base3
{
protected:
    int base3int;

public:
    void set_base3int(int a)
    {
        base3int = a;
    }
};

class Derived : public Base1, public Base2, public Base3
{
public:
    void show()
    {
        cout << "The value of base1 is : " << base1int << endl;
        cout << "The value of base2 is : " << base2int << endl;
        cout << "The value of base3 is : " << base3int << endl;
        cout << "The value of their sum is :" << base1int + base2int + base3int << endl;
    }
};

/*
the iniherited class will look like this:
Data Members:
    base1int --> protected
    base2int --> protected
    base3int --> protected
Mehtods :
  void set_base1int --> public
  void set_base2int --> public
  void set_base3int --> public

condition ke anusar derived class banate vakt hamein dhyan rakhana hai ki konksa data member aur method kya ho jayega
*/

int main()
{
    Derived shivkumar;
    shivkumar.set_base1int(25);
    shivkumar.set_base2int(5);
    shivkumar.set_base3int(4);
    shivkumar.show();
    return 0;
}