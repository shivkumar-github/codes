#include <iostream>
using namespace std;

double pow(double a, double n)
{

        if (n == 0)
                return 1;
        if (n < 0)
        {
                return 1 / pow(a, -n);
        }
        if (n > 0)
        {
                return a * pow(a, n - 1);
        }
}

int main()
{
        double a, b;
        cin >> a >> b;
        cout << pow(a, b);
        return 0;
}