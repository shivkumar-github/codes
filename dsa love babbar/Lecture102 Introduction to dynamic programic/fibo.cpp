/*
example of dp

*/

#include <iostream>
#include <vector>
using namespace std;

// TOPIC: by top down approach
int fib(int n, vector<int> &dp)
{
        // base case
        if (n == 0 || n == 1)
                return n;

        // step3
        if (dp[n] != -1)
                return dp[n];

        // step2
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
}

int main()
{
        // int n = 6;

        // vector<int> dp(n + 1, -1);

        // cout<< fib(n,dp) << endl;

        // TIME COMPLEXITY _ O(n)
        // SPACE COMPLEXITY _O(n) --> O(n+n)

        // TOPIC: by bottom up (tabulation)
        int n;
        // STEP 1:
        vector<int> dp(n + 1);

        // STEP2 - base cases
        dp[1] = 1;
        dp[0] = 0;

        // STEP3
        for (int i = 2; i <= n; i++)
        {
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << dp[n] << endl;

        // TIME COMPLEXITY _ O(n)
        // SPACE COMPLEXITY _O(n)


        // spcace optimisation
        // its nothing but the iterative way of the fibonacce 
        // with T.C = O(N) S.C. = O(1)


        return 0;
}
