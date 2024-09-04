/*
give long long integer square root of given long long integer number
 0 < num < 2^31 -1 
*/

#include <iostream>
#include <vector>
using namespace std;

long long int returnsqrt(long long int num) // using long long int as in question given that 0 < num < 2^31 -1 // phat na jayein
{
    long long int start = 0; // search space will be from 0 to num
    long long int end = num;
    long long int ans;
    while (start <= end)
    {
        long long int mid = (start + end) / 2;
        if (mid * mid == num)
        {
            return mid;
        }
        
        else if(mid * mid < num)
        {
            ans = mid; 
            start = mid + 1;
        }
        else if(mid * mid > num)
        {
            end = mid - 1;
        }
    }
    return ans;
}

 int main()
{
    long long int num = 0.4;
    cout<<returnsqrt(num)<<endl;
    return 0;
}