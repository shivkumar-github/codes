/*
Introduction to macro variables
    ->> why do we need macro variables?
    1. They do not consume any memroy during runtime as normal variables do
    2. these are the instructions you want to give to your computer before our programme actually runs
    3.  they are not data containers instead they are isntructions given to computer before programme runs hence it do not take memroy
    4. It also helps to maintain the code       
    you may also read the article https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/ in gfg (not recommended read only if neccessary) to explore about macro variables and it's types

Global variables 
    ->>  It is used for sharing a single variables within all the functions ->> just for information never use them 
    ->> It is considered as bad practice because anybody can modify it from anywhere and it's value will be changed in whole programme hence use reference variables for variable sharing

Just a point
    ->> we can use ternary operators to convert a if-else statement into a single line

Inline functions
    ->> it is used to reduce the time required to call a function and the memroy consumed by variables of that  function 
    ->> thought after giving explicite instructions it is finally dependent on decision of the compiler to make it explicite or not
    ->> when function is inline it's call is replaced by the body of that function before compilation
    ->> the decision of compiler depends upon different factors like function size, frequency of function calls etc.

Default Argument 
    ->> only 1 new thing ->> always make Default Argument to rightmost 
    for ex void func(int a, int b = 0, int c) ->> will throw error
*/

#include<iostream>
#define PI 3.14

// we can also define a function as macro
#define Area(r) (PI * r * r)
using namespace std;

void func(int a, int b = 0, int c) {}

int func(int a, int b){
    return (a>b) ? a : b;
}

int main(){
    int rad;
    cin >> rad;
    double area1 =  PI*rad*rad;
    double area2 = Area(rad);
    cout<< "The area1 of the circle is : " << area1 << endl;
    cout<< "The area2 of the circle is : " << area2 << endl;


    // int a, b;
    // cin >> a >> b;
    // int ans = func(a, b);
    // //  will be similar to int ans = (a>b) ? a : b;
    // cout<< "ans = " << ans << endl;
return 0;
}