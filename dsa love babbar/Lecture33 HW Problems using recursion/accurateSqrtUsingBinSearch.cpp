/*
/*
now we have to calculate precise square root of the num
*/

#include <iostream>
using namespace std;

int returnIntsqrt(int num, int s, int e)
{
        if (s > e)
                return -1;

        int mid = s + (e - s) / 2;
        int sqrt = -1;
        if (mid * mid == num)
        {
                sqrt = mid;
                return sqrt;
        }
        else if (mid * mid < num)
        {
                sqrt = mid;
                int possible = returnIntsqrt(num, mid + 1, e);
                if (possible != -1)
                {
                        sqrt = possible;
                }
        }
        else if (mid * mid > num)
        {
                int possible = returnIntsqrt(num, s, mid - 1);
                if (possible != -1)
                {
                        sqrt = possible;
                }
        }
        return sqrt;
}

double calcPrecFor1Dec(int num, double sqrt, double decno)
{
        double ans = 0;
        for (int i = 0; i <= 9; i++)
        {
                double tempsqrt = sqrt + (i * decno);
                if (tempsqrt * tempsqrt <= num)
                {
                        ans = i * decno;
                }
                else
                {
                        break;
                }
        }
        return ans;
}

double calcPreciseSqrt(int num, int precision)
{
        double precisesqrt = double(returnIntsqrt(num, 0, num));
        float decno = 1;
        // decno = 0.1, 0.01. 0.001 ....

        // for loop calculating for each decimal space
        for (int it = 0; it < precision; it++)
        {
                decno /= 10;
                precisesqrt = precisesqrt + calcPrecFor1Dec(num, precisesqrt, decno);
        }
        return precisesqrt;
}

int main()
{
        int num = 2000;
        cout << calcPreciseSqrt(num, 4);
        return 0;
}