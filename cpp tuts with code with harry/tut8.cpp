// Constants in C++
// Manipulator in C++
// Operator Precedence in C++

#include <iostream>
#include <iomanip> // it is a library that has the functions which can manipulate the input output in cpp

using namespace std;

int main()
{
    // *****************Constants in C++******************
    // int a = 34;
    // cout<<"The value of a was: "<<a;
    // a = 45;
    // cout<<"The value of a is: "<<a; // a is not a constant variable hence it can be changed further
    // const int a = 3; //any type of variable can be made constant in this way and if we try to change it in further code compiler will show error
    // cout<<"The value of a was: "<<a<<endl;
    // a = 45; // You will get an error because a is a constant
    // cout<<"The value of a is: "<<a<<endl;

    // Manipulators in C++
    // int a =3, b=78, c=1233;
    // cout<<"The value of a without setw is: "<<a<<endl;
    // cout<<"The value of b without setw is: "<<b<<endl;
    // cout<<"The value of c without setw is: "<<c<<endl;

    // cout<<"The value of a is: "<<setw(4)<<a<<endl; //this setw will set the width of output as 4
    // cout<<"The value of b is: "<<setw(4)<<b<<endl;
    // cout<<"The value of c is: "<<setw(4)<<c<<endl; // we have to write setw() before the variable

    // the output will be
    // The value of a is:    3
    // The value of b is:   78
    // The value of c is: 1233
    
    // Operator Precedence
//     Precedence	Operator	Associativity
// 1	Parentheses () Left-to-right
// 2	Unary prefix operators: ++, --, *, &, - (minus as negation)	Right-to-left
// 3	Multiplication, division, modulus: *, /, %	Left-to-right
// 4	Addition, subtraction: +, -	Left-to-right
// 5	Bitwise shift operators: <<, >>	Left-to-right
// 6	Relational operators: <, <=, >, >=	Left-to-right
// 7	Equality and inequality operators: ==, !=	Left-to-right
// 8	Logical AND operator: &	Left-to-right
// 9	Logical OR operator:	
// 10	Conditional operator: ?:	Right-to-left
// 11	Assignment operators: =, +=, -=, *=, /=, %=, &=,	#ERROR!
// 12	Comma operator: ,	Left-to-right

    // left to right
    int a = 3, b = 4;
    // int c = (a*5)+b;
    int c = ((((a * 5) + b) - 45) + 87);
    cout << c;
    return 0;
}
