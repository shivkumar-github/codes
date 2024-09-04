// Constructers in C++

#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    // Creating a cunstructor
    // Constructer is a special member function with same name as that of the class
    // It is used to initialise object of its class
    // It is automatically invoked whenever an object is created

    Complex(void); // constructer declaration
    // constructor can not have any return type, neither the void
    void printNumber()
    {
        cout << "Your complex number is :" << a << "+" << b << "i" << endl;
    }
};
Complex ::Complex(void) //----> this is a default constructer as it takes no value
{
    a = 10;
    b = 20;
    cout<<"hello world"<<endl;
}
int main()
{
    Complex c1, c2, c3;
    c1.printNumber();
    return 0;
}

/*
Properties of constructer :
1. It should be declared in the public section of the class
2. They are automatically invoked whenever an object is created
3. They can not have return type i.e. can not return values
4. It can have default arguments
5. We can not refer to their address
6. It has same name as that of the class
*/