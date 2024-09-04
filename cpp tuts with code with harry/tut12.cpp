// pointers in C++

#include <iostream>
using namespace std;

int main()
{
    // what is pointer?------>it is a data type which stores the address of other data types

    int a = 3;
    int* b = &a; // always write * after int/char etc to avoid the confusion

    // & -----> It is 'Address of' operator
    // cout<<"The address of a is "<<&a<<endl ;
    // cout<<"The address of a is "<<b<<endl ;

    // // * ----> It is dereference operator
    // cout<<"The value at address b is :"<<*b<<endl ;
    // cout<<"The value at address b is :"<<*(&a) ;

    // pointer to pointer
    int **c = &b;
    cout << "The address of b is :" << &b << endl;
    cout << "The address of b is :" << c << endl;
    cout << "The value at address c is :" << *c << endl;
    cout << "The value_at ( value_at( address(c) ) )  :" << **c << endl; // which wil be equal to value at address b i.e. the value of variable a

    return 0;
}