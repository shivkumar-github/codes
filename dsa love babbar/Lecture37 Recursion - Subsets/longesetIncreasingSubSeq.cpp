/*
https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459
 Longest Increasing Subsequence
Moderate
0/80
Average time to solve is 30m
Contributed by
198 upvotes
Asked in companies
Problem statement
For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.

Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.

For example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input :
6
5 4 11 1 16 8
Sample Output 1 :
3
Explanation of Sample Input 1:
Length of longest subsequence is 3 i.e. [5, 11, 16] or [4, 11, 16].
Sample Input 2:
3
1 2 2
Sample Output 2 :
2

*/

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> arr, int prevIndex, int index)
{
    if (index >= arr.size())
    {
        return 0;
    }

    // exclusion || not valid element
    int len = solve(arr,prevIndex,index+1);

    // inclusion
    if (prevIndex == -1 || arr[index] > arr[prevIndex]) // we can get length of decreasing sequence by changing the sign > to < 
    {
        len = max(len,1+solve(arr,index,index+1));
    }
    return len;
    
}

int longest(vector<int> arr)
{
    vector<int> forward;
    return solve(arr, -1, 0);
}

int main()
{
    vector<int> arr = {22, 5, 7, 2, 23, 10, 15, 21, 3, 17};
    int answer = longest(arr);
    cout<< answer << endl;
    return 0;
}