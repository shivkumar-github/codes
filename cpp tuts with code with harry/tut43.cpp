// Ambiguity Resolution in Inheritance in C++

#include <iostream>
using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "Hello World !! " << endl;
    }
};

class Base2
{
public:
    void greet()
    {
        cout << " Namaste !! " << endl;
    }
};

class Derived : public Base1, public Base2
{
public:
    void greet()
    {
        Base2::greet();
    }
};

class B
{
public:
    void say()
    {
        cout << "Good morning !!" << endl;
    }
};

class D
{
public:
    void say()
    {
        cout << "Good afternoon !!" << endl;
    }
};

int main()
{
    // Ambiguity1 --> two parent classes having method with same name

    Base1 Base1obj;
    Base1obj.greet();
    Base2 Base2obj;
    Base2obj.greet();
    Derived d1;
    d1.greet();

    /* Ambiguity2 ---> parent class and child class both have mehtod with same name
     In this case compiler will override the method say() of the base class and run the method already present in the child class
     Otherwise if child class don't have that method then the compiler will call the method in the parent class*/

    D Dobject1;
    Dobject1.say();

    // compiler by default run the method which is already written in its own body.
    //  But if the function “say” was not present in the class “D” then the compiler will run the method of the class “B”.

    return 0;
}