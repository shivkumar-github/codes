/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

// approach we don't know how to search directly in log n time complexity but we can find the peak element and find element separatly using the peak element

#include <iostream>
#include <vector>
using namespace std;

// 1. finding the peak element
int findPivotIndex(vector<int> arr, int s, int e)
{
    // there are two ways first we write condition when process to be terminated => if(s < e) or we may write upto when process to be executed=> (s <= e)
    if (s < e) // but this is better we don't write equal to as we are doing end = mid and not mid - 1
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[0])
        {
            int possible = findPivotIndex(arr, s, mid);
            if (possible != -1)
                return possible;
            else
                return mid;
        }
        else if (arr[mid] > arr[0])
            return findPivotIndex(arr, mid + 1, e);
    }
    return -1;
}

int binSearch(vector<int> arr, int s, int e, int key)
{
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            // int possible =
            return binSearch(arr, s, mid - 1, key);
            // if (possible != -1)
            // return possible;
        }
        else if (arr[mid] < key)
        {
            // int possible =
            return binSearch(arr, mid + 1, e, key);
            // if (possible != -1)
            // return possible;
        }
    }
    return -1;
}

int findInedx(vector<int> arr, int key)
{
    int n = arr.size();
    int ans = -1;
    // int peakind = peakIndex(arr, 0, arr.size() - 1);
    int pivot = findPivotIndex(arr, 0, n - 1);
    if (key < arr[n - 1])
    {
        return binSearch(arr, pivot, n - 1, key);
    }
    else
    {
        return binSearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    // vector<int> array = {1, 3}; // not a sorted rotated array
    // cout << findInedx(array, 0) << endl;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << findPivotIndex(arr, 0, arr.size() - 1) << endl;
    return 0;
}