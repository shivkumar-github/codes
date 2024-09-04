// Initialisation list in Constructor in C++

#include <iostream>
using namespace std;
/*
Syntax for initialisation list in Constructor :
constructor( argument-list) : initialisation section{
    assignment + other code;
}

class Test{
    int a,b;
    public:
    Test(int i, int j) :a(i), b(j){
        constructor body
    }
};
intialisation is used when constructor body is complex and we want variables to be declared at starting of the class
*/

class Test
{
    int a, b;

public:
    // Test(int i, int j) : a(i), b(j)
    // Test(int i, int j) : a(i), b(j+i)
    // Test(int i, int j) : a(i), b(2 * j)
    //  Test(int i, int j) : a(i), b(a+j)
    //  Test(int i, int j) : b(a+j), a(i) it will not give error as in class we have declared a first and then b hence a will be initialised first and also the order of b(a+j) and a(i) doesn't matter
    // Test(int i, int j) : b(j), a(i + b) //---> Red flag ---> this will create garbage value as a is declared first and if we initialise b first then this will run  
      Test(int i, int j) : b(j), a(i)
    {
        cout << "Constructor of Test class is called !" << endl;
        cout << "The value of a is :" << a << endl;
        cout << "The value of b is :" << b << endl;
    }
};
int main()
{
    Test t(4, 10);
    return 0;
}