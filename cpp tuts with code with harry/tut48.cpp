// Code Exapmles : Constructors in Derived Class

#include <iostream>
using namespace std;

/*
case 1:
class B: public A{
 // Order of execution of Constructors --> first A() then B()
};

case2:
class A: public B, public C{
//  Order of execution of Constructors --> first B() then C() and then A()
};

case3:
class A: public, virtual public C{
    // Order of execution of Constructors --> first C() then B() then A()
};

*/

// creating first base class
class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class Constructor is called !" << endl;
    }
    void printDataBase1(void)
    {
        cout << "The value of data1 is : " << data1 << endl;
    }
        ~Base1(){
        cout<< "The destructor of Base1 class is called! " << endl;
    }
};

// creating second base class
class Base2
{
    int data2;
public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 class Constructor is called !" << endl;
    }
    void printdataBase2(void)
    {
        cout << "The value of data2 is : " << data2 << endl;
    }
        ~Base2(){
        cout<< "The destructor of Base2 class is called! " << endl;
    }
};

// creating a derived class
class Derived : public Base1, public Base2
{
    int derived1, derived2;
public:
    Derived(int a, int b, int c, int d) : Base2(b), Base1(a)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class Constructor is called !" << endl;
    }
    void printDataDerived(void)
    {
        cout << "The value of derived1 is : " << derived1 << endl;
        cout << "The value of derived2 is : " << derived2 << endl;
    }
    ~Derived(){
        cout<< "The destructor of Derived class is called! " << endl;
    }
};

int main()
{
    Derived shivkumar(1, 2, 3, 4);
    shivkumar.printDataBase1();
    shivkumar.printdataBase2();
    return 0;
}

// i.e. constructor are invoked in the order of inheritance and distructors in the reverse order of inheritance