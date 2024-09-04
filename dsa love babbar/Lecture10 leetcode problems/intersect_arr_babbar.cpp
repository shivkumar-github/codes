/*
https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149

Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> intersect_arr;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            intersect_arr.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return intersect_arr;
}

// to solve it given time complextity we have to take advantage that the arrays are sorted in non decreasing order
//  **two pointer approach using i and j simultaneously
// time complexity of this code will be O(n + m ) space complexity = O(1);