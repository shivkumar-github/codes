/*
Leet Code
https://leetcode.com/problems/peak-index-in-a-mountain-array/
852. Peak Index in a Mountain Array
Medium
An array arr is a mountain if the following properties hold:
                                                   /\
                                                  /  \
                 arr[m] < arr[m + 1]    ==>  /    \  ==> arr[m] > arr[m + 1]
                                                /      \
                                               /        \
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) ==> O(logn) time complexity.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        int m;
        while (s < e)
        {
            m = s + (e - s) / 2;
            if (arr[m] < arr[m + 1])
            {
                s = m + 1;
            }
            else
            { // if arr[m] > arr[m + 1]
                e = m;
            }

           // DOUBT: why not 
            // if (arr[m] <arr[m - 1])
            // {
            //     e = m - 1;
            // }
            // else
            // { // if arr[m] > arr[m + 1]
            //     s = m;
            // }

        } // at this point s(when loop es) and e will be equal
        return s;
    }
};

int main()
{

    vector<int> array = {1, 2, 3, 6, 7, 11, 8, 4, 3, 2, 1};
    Solution S1;
    cout << "Peak Index is : " << S1.peakIndexInMountainArray(array) << endl;

    return 0;
}