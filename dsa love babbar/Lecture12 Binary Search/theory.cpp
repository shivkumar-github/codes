/*
This is the theory lecture for binary search.
=> We apply binary search when searching a key in a sorted array
=> In binary search we improve time complexity from O(n) to O(log n) (base of log is 2)
=> It has three main steps
   1. Finding the index of middle term
   2. Compairing that with element at the middle index of array.
   3. If both are equal then index of that element is answer.
   4. else If key > middle term then pick array after the middle term
   5. else pick array before middle term
   6. Then again back to step 1
*/

#include <iostream>
#include <vector>
using namespace std;

// using recursion
int binSearch(vector<int> arr, int key, int s, int e)
{
        if (s > e)
        {
                return -1;
        }
        else
        {
                int mid = s + (e - s) / 2;
                if (arr[mid] == key)
                {
                        return mid;
                }
                else if (arr[mid] < key)
                {
                        return binSearch(arr, key, mid + 1, e);
                }
                else
                {
                        return binSearch(arr, key, s, mid - 1);
                }
        }
}

// non recursive
int binSearch1(vector<int> arr, int key)
{
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e)
        {
                int mid = s + (e - s) / 2;
                if (arr[mid] == key)
                {
                        return mid;
                }
                else if (arr[mid] < key)
                {
                        s = mid + 1;
                }
                else
                {
                        e = mid - 1;
                }
        }
        return -1; // when not found
}

int main()
{
        vector<int> odd = {1, 2, 4, 5, 6, 8, 22};
        cout << binSearch(odd, 22, 0, odd.size() - 1);
        cout << binSearch1(odd, 22);
        return 0;
}