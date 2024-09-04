/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-(2^31)-->INT_MIN , (2^31)-1---> INT_MAX], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

#include <iostream>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;
        while (x)
        {
            int digit = (x % 10);

            if (ans<(INT32_MIN/10) || ans>(INT32_MAX/10))
            {
                return 0;
            }
            

            ans = ans * 10 + digit; // *before* this step answer ki value honi chahiye (INT_MIN/10)<ans<(INT_MAX/10) --> as answer is multiplied by 10 after this step
            x = x/10;
        }
    }
    int reverse(int x){
        int ans = 0;
    }
};
 int main(){
    return 0;
 }
 // just asked to build the class