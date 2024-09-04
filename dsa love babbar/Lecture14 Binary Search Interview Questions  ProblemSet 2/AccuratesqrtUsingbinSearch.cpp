/*
now we have to calculate precise square root of the num
*/

#include <iostream>
using namespace std;

int returnsqrt(int num)
{
    int start = 0;
    int end = num;
    int ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid * mid == num)
        {
            return mid;
        }

        else if (mid * mid < num)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (mid * mid > num)
        {
            end = mid - 1;
        }
    }
    return ans;
}

double morePrecision(double num, int precision, int tempSol)
{
    double factor = 1;
    double preciseSol = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10; // 1 => tempSol.1 => tempSol.01 to store
        // my approach - 1
        // int iterator = 10; // as we want to go as tempSol.1 => tempSol.2 => tempSol.3....=> tempSol.9 => 1.0 i.e. 10 times and again tempSol.01 => tempSol.02 => tempSol.03....=>tempSol.09 => tempSol.10 
        // while(iterator--)
        // {
        //     if ((preciseSol + factor) * (preciseSol + factor) < num)
        //     {
        //         preciseSol = preciseSol + factor;
        //     }
        //     else if ((preciseSol + factor) * (preciseSol + factor) == num)
        //     {
        //         preciseSol = preciseSol + factor;
        //         return preciseSol;
        //     }
        //     else if ((preciseSol + factor) * (preciseSol + factor) > num)
        //     {
        //         // nothing do do
        //     }
        //  }
        for (double j = tempSol; j  * j  <=num; j = j + factor)
        {
            preciseSol = j;
        }
    }
    return preciseSol;
}

int main()
{
    double num = 6.25;
    cout << "Enter the number : ";
    // cin >> num;
    int tempSol = returnsqrt(num);
    cout << "Answer is " << morePrecision(num, 3, tempSol) << endl;
    return 0;
}

