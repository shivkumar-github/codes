/*
coding ninjas
https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557
Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards.
Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11
// question same  as that of book allocation problem
// all work will be done when all painers will finish their job => when the painter having maximum length to paint will complete his work
// maximum time(i.e. length of board) taken by a painter in the distibution should be minimum => which indicates the binary search can be applied
*/

#include <iostream>
#include <vector>
using namespace std;

int totalLength(vector<int> &lenths)
{
    int sum = 0;
    for (int i = 0; i < lenths.size(); i++) sum += lenths[i];
    return sum;
}

bool isPossibleSol(vector<int> &lengths, int k, int mid)
{
    int painterCount = 1;
    int lengthToPainter = 0;
    for (int i = 0; i < lengths.size(); i++)
    {
        if (lengthToPainter + lengths[i] <= mid) lengthToPainter += lengths[i];

        else //if (lengthToPainter + lengths[i] > mid)
        {
            painterCount++;
            if (painterCount > k || lengths[i] > mid) return false;//include this condition or not
            lengthToPainter = lengths[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &lengths, int k)
{
    int start = 0;
    int end = totalLength(lengths); // => as search space => a painter can paint minimum 0 and maximum sum of all
    int ans = end;               // why -1 => minimum assigned length can be 0 so -1 (a non possible value)
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossibleSol(lengths, k, mid)==1)
        {
            end = mid - 1;
            ans = mid;
        }
        else start = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> lengths = {48, 90};
    int painters = 2;
    cout << findLargestMinDistance(lengths, painters) << endl;
    return 0;
}