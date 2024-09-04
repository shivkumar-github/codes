#include <iostream>
#include <vector>
using namespace std;

int findPivotIndex(vector<int> arr, int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[0])
        {
            int possible = findPivotIndex(arr, s, mid);
            if (possible != -1)
                return possible;
            return mid;
        }
        else if (arr[mid] > arr[0])
            return findPivotIndex(arr, mid + 1, e);
    }
    return -1;
}

int binSearch(vector<int> arr, int s, int e, int target)
{
    if (s <= e)
    {
        if (target > arr[e] || target < arr[s])
            return -1; // not neccessary but trying to reduce number of cases
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binSearch(arr, s, mid - 1, target);
        else if (arr[mid] < target)
            return binSearch(arr, mid + 1, e, target);
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int pivot = findPivotIndex(nums, 0, n - 1);
    if (target < nums[n - 1])
        return binSearch(nums, pivot, n - 1, target);
    else
        return binSearch(nums, 0, pivot - 1, target);
}

int main()
{
    vector<int> arr = {1};
    cout << search(arr, 0) << endl;
    return 0;
}