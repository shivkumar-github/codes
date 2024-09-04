/*

*/

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    //
    if (s >= e)
    {
        return mid;
    }
    if (arr[mid] > arr[s])
    {
        return getPivot(arr, mid + 1, e);
    }
    else
    {
        return getPivot(arr, s, mid);
    }
} // for more understanding look image find pivot Explanation image in lecture 13 folder

int main()
{
    vector<int> arr = {8, 10, 17, 1, 3};
    int pivotIndex = getPivot(arr, 0, 4);
    cout << pivotIndex << endl;
    return 0;
}