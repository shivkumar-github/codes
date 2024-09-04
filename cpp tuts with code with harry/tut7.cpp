
#include <iostream>

using namespace std;

int c = 45;

int main()
{

    //*************Build in Data types****************
    // int a, b, c;
    // cout<<"Enter the value of a:"<<endl;
    // cin>>a;
    // cout<<"Enter the value of b:"<<endl;
    // cin>>b;
    // c = a + b;
    // cout<<"The sum is "<<c<<endl;
    // cout<<"The global c is "<<::c;
    // to access value of global variable in presence of local variable we use double semicolon(::) which is called scope resolution operator and then variable name

    // ************* Float, double and long double Literals****************
    float d = 34.4F;
    long double e = 34.4L;
    cout << "The size of 34.4 is " << sizeof(34.4) << endl;   // A decimal number is double by default and not float
    cout << "The size of 34.4f is " << sizeof(34.4f) << endl; // both the f and F have same meaning i.e.
    cout << "The size of 34.4F is " << sizeof(34.4F) << endl;
    cout << "The size of 34.4l is " << sizeof(34.4l) << endl;
    cout << "The size of 34.4L is " << sizeof(34.4L) << endl;
    cout << "The value of d is " << d << endl
         << "The value of e is " << e;

    // *************Reference Variables****************
    // Rohan Das----> Monty -----> Rohu ------> Dangerous Coder these are the different names of rohan das but their value is same
    int x = 6;
    int &y = x; // reference variables share same location hence change in value of any one will cause change in others

    // *************Typecasting****************
    int a = 45;
    float b = 45.46;
    cout << "The value of a is " << (float)a << endl; // both the statements float(a) and (float)a have the same meaning
    cout << "The value of a is " << float(a) << endl;

    cout << "The value of b is " << (int)b << endl;
    cout << "The value of b is " << int(b) << endl;
    int c = int(b); // we can also use typecasting to assign integer part of a float variable (and other types like double , long double ) to another variable

    cout << "The expression is " << a + b << endl;
    cout << "The expression is " << a + int(b) << endl;
    cout << "The expression is " << a + (int)b << endl;

    return 0;
}