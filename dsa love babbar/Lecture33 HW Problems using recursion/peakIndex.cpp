/*
Leet Code
https://leetcode.com/problems/peak-index-in-a-mountain-array/
852. Peakind Index in a Mountain Array
Medium
An array arr is a mountain if the following properties hold:
                                                   /\
                                                  /  \
                 arr[mid] < arr[mid + 1]    ==>  /    \  ==> arr[mid] > arr[mid + 1]
                                                /      \
                                               /        \
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) ==> O(logn) time complexity.
*/
// x > y and x >= y - 1
#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> arr, int s, int e)
{
    if (s + 1 >= e)
    { // s > e and s >= e - 1
        return e;
    }
    int mid = s + (e - s) / 2;
    int peakind;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // we have to add this condition as without this condition we will search for the array though the peak element is found and hence no use of using binary search and time complexity will also increase leading to runtime errors
    {
        peakind = mid;
    }
    else if (arr[mid] > arr[mid + 1])
    {
        peakind = peakIndexInMountainArray(arr, s, mid);
    }
    else if (arr[mid] > arr[mid - 1])
    {
        peakind = peakIndexInMountainArray(arr, mid, e);
    }
    return peakind;
}

// another approach
// int peakIndex(vector<int> &arr, int s, int e)
// {
//     if (s <= e)
//     {
//         int ans = -1;
//         int mid = s + (e - s) / 2;
//         if (arr[mid] > arr[mid - 1] && (mid > 0 && mid < arr.size()))
//         {
//             ans = mid;
//             int possible = peakIndex(arr, mid + 1, e);
//             if (arr[possible] > arr[mid] && possible != -1)
//                 ans = possible;
//         }
//         else if (arr[mid] > arr[mid + 1] && (mid > 0 && mid < arr.size()))
//         {
//             ans = mid;
//             int possible = peakIndex(arr, s, mid - 1);
//             if (arr[possible] > arr[mid] && possible != -1)
//                 ans = possible;
//         }
//     }
//     else
//         return -1;
// }

// int peak(vector<int> arr, int s, int e)
// {
//     if (s + 1 >= e)
//     {
//         return e;
//     }
//     int mid = s + (e - s) / 2;
//     int peakind;
//     // if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
//     // {
//     //     peakind = mid;
//     //     return peakind;
//     // }
//     if (arr[mid] < arr[mid + 1])
//     {
//         peakind = peak(arr, mid, e);
//     }
//     else if (arr[mid] > arr[mid - 1])
//     {
//         peakind = peak(arr, s, mid);
//     }
// }

//     int peakIndexInMountainArray(vector<int>& arr)     {
//         int start = 0;
//         int end = arr.size()-1;
//         return peak(arr, start, end);
//         }

int main()
{
    // vector<int> array = {1, 2, 3, 6, 7, 11, 8, 4, 3, 2, 1};
    // vector<int> array = {24,69,100,99,79,78,67,36,26,19};
    // int ans = peakIndexInMountainArray(array,0,9);
    // cout << peakIndexInMountainArray(array,0,9) << endl;
    vector<int> array = {3, 1};
    cout << peakIndexInMountainArray(array, 0, array.size() - 1);
    return 0;
}