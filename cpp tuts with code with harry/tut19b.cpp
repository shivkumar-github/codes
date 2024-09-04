// Operator Overloading in C++
// not taught by code with harry

#include <iostream>
using namespace std;

class Complex
{
    float real, img;

public:
    Complex(float r=0,float i=0){
        real=r;
        img=i;
    }
    void PrintComplex()
    {
        cout << "The complex number is : (" << real << ") + (" << img << ") i" << endl;
    }
    // Operator Overloading
    // syntax:
    // return_type 'operator keyword' operator_name(optional arguement){
    // function body
    // }

    // overloading of binary operator (work on two operands)
    Complex operator +(Complex c)
    {
        Complex temp; // Another Complex object to store the addition
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    // overloading of unary operator (works on only one operand)
    Complex operator -(){
        Complex temp; // Another Complex object to store the negative of the complex
        temp.real=-real;
        temp.img=-img;
        return temp;
    }
};

int main()
{
    Complex c1(4,6);
    Complex c2(5,8);
    Complex c3 = c1+c2;
    c3.PrintComplex();
    Complex c4=-c1;
    c4.PrintComplex();
    return 0;
}

// C++ allows you to specify more than one definition for an operator in the same scope, which is called operator overloading.
// You can redefine or overload most of the built-in operators available in C++
// This can be only used on user defined data types only , behavior of operators can not be chanṇged for inbuilt data types 
// It is a type of polymorphism in which an operator is overloaded to give user defined meaning to it.
// Almost any operator can be overloaded in C++. However there are few operator which can not be overloaded. Operator that are not overloaded are follows-
// 1.scope resolution operator (::)
// 2.sizeof
// 3.member selector -(.)
// 4.member pointer selector - (*)
// 5.ternary operator (?:)