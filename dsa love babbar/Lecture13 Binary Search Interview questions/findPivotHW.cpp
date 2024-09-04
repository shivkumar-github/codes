/*
Consider an array which is increasingly sorted in some part and decreasingly sorted in another part
then the element at which type of sorting changes is called pivot element in an array
for ex array = {7, 9, 1, 2, 3} here array is decreasingly sorted upto 1 and then again increasingly sorted onwards therefore pivot element is 1 at index 2

there are two possible pivot point we will consider the pivot in the second point

 The pivot is essentially the index where the sorted array rotation occurred. hence the element at end will be always less than element at start
*/

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> &array)
{
    int ans = -1;
    int start = 0;
    int end = array.size();
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (array[mid] > array[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid; // -1 nhi kiya kyunki humein second part of graph mein jo pivot hai vo chahiye
        }
        ans = mid;
        mid = start + (end - start) / 2;
    }
    return ans;
} // for more understanding look image find pivot Explanation image in lecture 13 folder

int main()
{
    vector<int> array = {8, 10, 17, 1, 3};
    cout << "The pivot element index in given array is : " << getPivot(array) << endl;
    return 0;
}