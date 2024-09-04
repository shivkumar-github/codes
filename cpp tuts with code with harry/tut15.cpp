// functions and function prototypes in C++

#include <iostream>
using namespace std;

// function prototype  --> using function declaration prototype we tell the compiler ki function aage milega
// no need to use prototype when defining the function before main function
// type function_name (arguments);
// int sum(int a , int b); --> acceptable
// int sum(int a,b); -->not acceptable
int sum(int, int); //--> acceptable  (telling only the type) defination mein sirf type batane se bhi kaam chal jayega

// declaration of void sum function
void g(void);
// void g() ; //both are acceptable

void sum(void);
int main()
{
    int a, b;
    cout << "Enter the first number" << endl;
    cin >> a;
    cout << "Enter the second number" << endl;
    cin >> b;
    cout << "The sum is :" << sum(a, b) << endl; // these are arguments i.e. actual parameters which are used to send values// this function call
    g();
    return 0;
}

// defination of int sum function
int sum(int a, int b)
{ // these are parameters i.e. formal parameters which are used to accept the value
    return a + b;
}

void g()
{
    cout << "\nHello, Good Morning";
}