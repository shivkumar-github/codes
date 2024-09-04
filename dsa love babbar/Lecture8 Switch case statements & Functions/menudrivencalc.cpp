/*
designing a menu driven calculator to understand use of switch case
*/

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    char op;
    cout<< "Enter the first number : " << endl;
    cin >> num1 ;
    cout<< "Enter the second number : " << endl;
    cin >> num2 ;
    cout<< "Enter the operation you want to perform : ( +, -, *, /, %)" << endl;
    cin >> op ;

    switch (op)
    {
    case '+':
        cout<< "num1 + num2 = " << (num1 + num2 ) << endl;
        break;
    case '-':
        cout<< "num1 - num2 = " << (num1 + num2 ) << endl;
        break;
    case '*':
        cout<< "num1 * num2 = " << (num1 * num2 ) << endl;
        break;
    case '/':
        cout<< "num1 / num2 = " << (num1 / num2 ) << endl;
        break;
    case '%':
        cout<< "num1 % num2 = " << (num1 % num2 ) << endl;
        break;
    
    default:
    cout<< "Please enter a valid operation ! " << endl;
        break;
    }

    return 0;
}