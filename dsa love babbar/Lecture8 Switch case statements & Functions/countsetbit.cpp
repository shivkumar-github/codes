/*
counting set bits in two numbers
*/

#include <iostream>
using namespace std;
int countsetbits(int num1, int num2)
{
    int setbits = 0;
    while (num1)
    {
        if (num1 & 1 == 1)
        {
            setbits++;
        }
        num1 = num1 / 2;
    }
    while (num2)
    {
        if (num2 & 1 == 1)
        {
            setbits++;
        }
        num2 = num2 / 2;
    }

    return setbits;
}
int main()
{
    int num1, num2;
    cout << "Enter the first number : " << endl;
    cin >> num1;
    cout << "Enter the second number : " << endl;
    cin >> num2;
    cout << "The value of setbits in both the integers is : " << countsetbits(num1, num2) << endl;

    return 0;
}