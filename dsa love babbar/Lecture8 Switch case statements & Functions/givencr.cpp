/*
give value of ncr
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int ncr()
{
    int n, r;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    cout << "Enter the value of r : " << endl;
    cin >> r;
    return (factorial(n) / (factorial(n - r) * factorial(r)));
}

int main()
{
    cout << "The value of nCr is : " << ncr();
    return 0;
}