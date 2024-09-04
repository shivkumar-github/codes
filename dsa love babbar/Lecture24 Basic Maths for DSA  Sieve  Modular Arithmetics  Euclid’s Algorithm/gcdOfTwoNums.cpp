/*
gcd Eucledian algorithm
https://www.codingninjas.com/studio/library/gcd-euclidean-algorithm
*/

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        // jo bada hai usme se chhote ko minus karo
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    // jab tak dono equal nahi ho jate , jab equal honge to a = b = gcd hoga
    return b; // or we can also write return a;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2);
    return 0;
}