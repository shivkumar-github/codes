/*
Leet Code
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>
#include <vector>
using namespace std;

int findPivotIndex(vector<int> &array)
{
    int ans = -1;
    int start = 0;
    int end = array.size() - 1;
    int count = 0;
    while (start < end)
    {
        int mid = (end + start) / 2;
        if (array[mid] > array[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        ans = mid;
    }
    return ans;
}

int binarySearch(vector<int> &array, int start, int end, int key)
{
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] > key)
        {
            end = mid - 1;
        }
        else if (array[mid] < key)
        {
            start = mid + 1;
        }
    }
    return -1;
}
int findInedx(vector<int> &array, int key)
{
    int ans = -1;
    int pivot = findPivotIndex(array);
    if (key < array[pivot]) // key < arr[pivot] return -1 as pivot is minimum in any array
    {
        return -1;
    }
    if (key < array[0])
    {
        ans = binarySearch(array, pivot, (array.size() - 1), key);
    }
    else if (key > array[0])
    {
        ans = binarySearch(array, 0, pivot, key);
    }
    return ans;
}
int main()
{
    vector<int> array = {12, 15, 18, 2, 4};
    int key = 4;
    cout << "index of " << key << " in the given array is : " << findInedx(array, key);
    return 0;
}

// Time Complexity O(log n) + O(log n) = O(log n)