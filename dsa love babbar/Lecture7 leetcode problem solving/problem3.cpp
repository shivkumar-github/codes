/*
complement of a base 10 integer
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int m = n;
        int mask = 0;
        if (n == 0)
        {
            return 1; // because when m=n=0 it wont enter in the loop so we have to add special case 
            // consider edge cases in every problem
        }

        while (m)
        {
            mask = ((mask << 1) | 1); // bitwise or operation
            m = m >> 1;
        }
        cout << "mask = " << mask << endl;
        int ans;
        ans = ((~n) & mask);
        return ans;
    }
};
int main()
{
    Solution S1;
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    cout << S1.bitwiseComplement(num) << endl;
    return 0;
}