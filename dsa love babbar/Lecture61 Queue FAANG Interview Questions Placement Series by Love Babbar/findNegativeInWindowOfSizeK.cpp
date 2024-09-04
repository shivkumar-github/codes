// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

// O(n) time complexity and space complexity O(n)
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    // queue can solve this question in O(n) tc
    vector<long long> ans;
    queue<int> q;

    // pushing first k elements to create first window
    for (long long i = 0; i < K; i++) if (A[i] < 0) q.push(i);

    for (long long i = 0; i <= N - K; i++)
    {
        // if stack is not empty the we have found required element
        if (!q.empty()) ans.push_back(A[q.front()]);
        // no negative element
        else ans.push_back(0);
        // pop element which is not required in next window
        if (!q.empty() && q.front() <= i) q.pop();
        // // push the further element in Q if it is negative
        if (A[i + K] < 0) q.push(i + K);
    }
    return ans;
}


// for the same approaches but a bit long code, view your gfg submissions on this problem