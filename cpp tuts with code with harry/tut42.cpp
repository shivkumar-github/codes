// Inheritance Exercise in C++

#include <iostream>
#include <cmath>
using namespace std;
/*
Create 2 classes:
     1. SimpleCalculator - Takes input of 2 numbers using a utility function and performs +,-,*,/ and
     dislpays the result using another utility function
     2. ScientificCalculator - Takes input of 2 numbers using a utility function and
     performs any four operations of your choice and displays the results using another function.

    Create another HybridCalculator and inherit it using these 2 classes :
    Q1. What type of inheritance are you using ? ---> Multiple inheritance
    Q2. Which mode of inheritance are you using ? ---> public inheritance
    Q3. Create an object of HybridCalculator and display the results of simple and scientific calculator.
    Q4. How code reusabitility is implemented ? ---> no need to write all methods and data members again in new class
*/

class Simple_Calculator
{
    float Simple_num1, Simple_num2;

public:
    void Simple_Calculator_set_data(float a, float b)
    {
        Simple_num1 = a;
        Simple_num2 = b;
    }

    void Simple_Calculator_display()
    {
        cout << "first number + second nubmer = " << Simple_num1 + Simple_num2 << endl;
        cout << "first number - second nubmer = " << Simple_num1 - Simple_num2 << endl;
        cout << "first number * second nubmer = " << Simple_num1 * Simple_num2 << endl;
        cout << "first number / second nubmer = " << Simple_num1 / Simple_num2 << endl
             << endl;
    }
};

class Scientific_Calculator
{
    float Scientific_num1, Scientific_num2;

public:
    void Scientific_Calculator_set_data(float a, float b)
    {
        Scientific_num1 = a;
        Scientific_num2 = b;
    }
    void Scientific_Calculator_display()
    {
        cout << "The square root of first number is : " << sqrt(Scientific_num1) << endl;
        cout << "The square root of second number is : " << sqrt(Scientific_num2) << endl;
        cout << "The cube root of first number is : " << cbrt(Scientific_num1) << endl;
        cout << "The cube root of second number is : " << cbrt(Scientific_num2) << endl;
        cout << "The square of first number is : " << Scientific_num1 * Scientific_num1 << endl;
        cout << "The square of second number is : " << Scientific_num2 * Scientific_num2 << endl;
        cout << "The cube of first number is : " << Scientific_num1 * Scientific_num1 * Scientific_num1 << endl;
        cout << "The cube of second number is : " << Scientific_num2 * Scientific_num2 * Scientific_num2 << endl
             << endl;
        // we can also add
        cout << "The value of sine of first number is : " << sin(Scientific_num1) << endl;
        cout << "The value of sine of second number is : " << sin(Scientific_num2) << endl;
        cout << "The value of cosine of second number is : " << cos(Scientific_num2) << endl;
        cout << "The value of cosine of second number is : " << cos(Scientific_num2) << endl;
        cout << "The value of e raised to the power first number is : " << exp(Scientific_num1) << endl;
        cout << "The value of e raised to the power second number is : " << exp(Scientific_num2) << endl;
    }
};

class Hybrid_Calculator : public Simple_Calculator, public Scientific_Calculator
{
    float num1, num2;

public:
    // creating a constructor so that as soon as the object is created the process will start automatically
    Hybrid_Calculator()
    {
        cout << "Enter first number : ";
        cin >> num1;
        cout << "Enter second number : ";
        cin >> num2;
        cout << endl
             << "Calculations on these two numbers are :" << endl
             << endl;
        // inside constructor of child class Hybrid_Calculator calling all the functions in parent classes
        Simple_Calculator_set_data(num1, num2);
        Simple_Calculator_display();
        Scientific_Calculator_set_data(num1, num2);
        Scientific_Calculator_display();
    }
};
int main()
{
    Hybrid_Calculator calc1;
    return 0;
}