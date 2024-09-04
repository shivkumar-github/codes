/*
Leet Code :-
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
1752. Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

*There may be duplicates in the original array.*

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.


Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
*/

#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &nums)
{
    int pairCount = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        // why not = -> because {1, 1, 1, 1} then we should not increase it's count
        {
            pairCount++;
        }
    }
    if (nums[0] < nums[nums.size() - 1])
    {
        pairCount++;
    }
    return pairCount <= 1;
}
/*
if pairCount is the number of pairs such that nums[0] < nums[nums.size()-1] or nums[i-1] > nums[i]
there are theree possible cases
I. an array sorted  in non decreasing order (i.e. rotated by 0 positions as given in question) => pairCount = 1
{1, 2, 3, 4, 5}

II. an array sorted in non decreasing order and rotated by greater than 0 postions => pairCount = 1
{3, 4, 5, 1, 2}

III. an array which is not rotated sorted array pairCount = pairCount > 1
{3, 5, 7, 7, 7}

IV. an array  having all elements equal => pairCount = 0
{1, 1, 1, 1, 1}

*/
int main()
{
    vector<int> arr1 = {3, 4, 5, 1, 2};
    cout << check(arr1) << endl;
    vector<int> arr2 = {2, 1, 3, 4};
    cout << check(arr2) << endl;
    return 0;
}