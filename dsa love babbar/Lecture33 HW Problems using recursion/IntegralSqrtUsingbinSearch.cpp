/*
give a long long integer square root of a given number
0 < num < 2^31 -1
*/

#include <iostream>
using namespace std;
int count = 0;

long long int returnsqrt(long long int num, int s, int e)
{
        if (s > e)
                return -1;
        int sqrt = -1; // we have to initialise sqrt as -1 because if at now mid * mid > num and then mid-1 < s (i.e. e < s) then for mid possible = -1 hence no value will be assigned to sqrt and hence function will return garbage value (for ex mid = 10 when num =95)
        // and -1 because we have mentioned it as condition
        int mid = s + (e - s) / 2;
        if (mid * mid == num)
                return mid;
        else if (mid * mid < num)
        {
                sqrt = mid;
                int possible = returnsqrt(num, mid + 1, e);
                if (possible != -1)
                {
                        sqrt = possible;
                }
        }
        else if (mid * mid > num)
        {
                int possible = returnsqrt(num, s, mid - 1);
                if (possible != -1)
                        sqrt = possible;
        }
        return sqrt;
}

int main()
{
        for (long long int i = 0; i < 100; i++)
                cout << "i = " << i << " and sqrt of i = " << returnsqrt(i, 0, i) << endl;

        return 0;
}