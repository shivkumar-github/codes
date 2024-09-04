/*
fibonacce series
*/

#include <iostream>
using namespace std;

int fib(int n)
{
    // according to question indexing starts from 0
    // base case
    if (n <= 1)
    {
        return n;
    }

    // recursive relation
    return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << n << " th term in fibinacce series is : " << fib(n) << endl;

    int f = 0;
    int s = 1;
    int l = f + s;
    if (n <= 1)
    {
        return n;
    }
    for (int i = 2; i < n; i++)
    {
        f = s;
        s = l;
        l = f + s;
    }
    cout << n << " th term in fibinacce series is : " << l << endl;
    return 0;
}