/*
Given an integer n, return true if it is a power of 2. Otherwise, return false.
An integer n is power of , if there exist and integer x such that 2^x=n
*/

#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
public:
    bool isPowerofTwo(int n)
    {
        // int ans = 1;
        // for (int i = 0; i <= 30; i++) // as max int = 2^31 - 1
        // {
            /* logic 1 :
             if((( m / 2) - float(int(m/2)))!= 0 ){ // this approach can not be used to to errors in floating point */

            // logic 2
            // if (pow(2, i) == n)
            // {
            //     return true;
            // }

            // // logic 3

            // if (ans == n)
            // {
            //     return true;
            // }
            // if (ans <= INT32_MAX/2)
            // {
            // ans *= 2; // have to write updation after condition otherwise n=1 wont be included
            // }
            // }
            //      return false;

        //     //  LOGIC 4
        //     //  LOGIC 3 can be implemented using
        //     if (ans!=n  && ans <= INT32_MAX / 2 )
        //     {
        //         ans *= 2;  // have to write updation after condition otherwise n=1 wont be included
        //     }
        //     return ans==n;
        // }

        // LOGIC 5
        if (n<=0)
        {
            return false;
        }
        return (n&(n-1))==0;
    }
};

int main()
{
    Solution S1;
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    cout << S1.isPowerofTwo(num);
    return 0;
}