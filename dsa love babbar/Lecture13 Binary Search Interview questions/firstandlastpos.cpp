/*
Leet Code question
Find First and Last Position of Element in Sorted Array

Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1.
2. 'arr' may contain duplicate elements.

Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1

Output: 1 2

Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
*/

#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int first_occurance(vector<int> &arr, int n, int key)
{
    int start = 0, end = n - 1, first = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] == key)
        {
            first = mid;
            end = mid - 1;
        }
    }
    return first;
}

int last_occurance(vector<int> &arr, int n, int key)
{
    int start = 0, end = n - 1, last = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] == key)
        {
            last = mid;
            start = mid + 1;
        }
    }
    return last;
}

pair<int, int> first_and_last_pos(vector<int> &arr, int n, int key)
{
    pair<int, int> p;
    p.first = first_occurance(arr, n, key);
    p.second = last_occurance(arr, n, key);
    return p;
}

int main()
{
    vector<int> array = {0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5};
    cout << "First occurance = " << first_occurance(array, 12, 3) << " and last occurance = " << last_occurance(array, 12, 3) << endl;
    cout << "first occurance = " << first_and_last_pos(array, array.size(), 3).first << " and last occurance = " << first_and_last_pos(array, array.size(), 3).second << endl;
    return 0;
}

/*
If same array is given and we are asked total number of occurance then we can solve it using two appraoches 
1. Linear search with O(n) => in worst case pura array search maro
2. Binary search with O(log n) time complexity => pehle first last nikalo aur usse total number of occurances find karo last - first +1
*/