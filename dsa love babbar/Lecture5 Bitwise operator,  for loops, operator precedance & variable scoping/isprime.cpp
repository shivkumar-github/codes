/*
to check whether the given number is prime or not
*/

#include <iostream>
using namespace std;

void checkPrime(int n)
{
    bool isprime = 1;
    // due to bool variable the conditions when num is 1 or two are automatically included
    for (int i = 2; i < n; i++)
    {
        if (n % 2 == 0)
        {
            isprime = 0;
            break;
        }
    }
    if (isprime == 1)
    {
        cout << "The number is prime. " << endl;
    }
    else
    {
        cout << "The number is not prime. " << endl;
    }
}
int main()
{
    int num;
    cout << "Enter the value of number : ";
    cin >> num;

    checkPrime(num);
    return 0;
}