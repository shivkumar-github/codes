/*
Leet Code
https://leetcode.com/problems/count-primes/
when we are asked to find number of prime numbers befire a number
traditionally we will write a code which 1st takes number upto n and then for each number we will check if that number is prime number
it's time complexity will be O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n + 1, true); // -1 as strictly less than n

        // pehle sare prime hai aise assume karo
        prime[0] = prime[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;
                for (int k = i * 2; k < n; k += i)
                {
                    prime[k] = false;
                }
            }
        }
        return count;
    }
};

// time complexity = O(n(log(logn))) --> n* (1/2 + 1/3 + 1/5 + 1/7 + 1/11)

int main()
{
    int n;
    cin >> n;
    Solution S1;
    cout << S1.countPrimes(n) << endl;
    return 0;
}