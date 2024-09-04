/*
calculating 2s power using recursion
*/

#include <iostream>
using namespace std;

int power(int n)
{
    if (n == 0)
    {
        return 1;
    }
    // int smallerProblem = power(n - 1);
    // int biggerProblem = 2 * smallerProblem;
    // return biggerProblem;
    return 2 * power(n-1);
}

int main()
{
    int input;
    cout<< "Enter the number : " << endl;
    cin >> input ;
    int ans = power(input);
    cout<< "ans = " << ans << endl;

    return 0;
}