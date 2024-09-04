/*rotate array to left
Coding ninjas problem
// https://www.codingninjas.com/studio/problems/rotate-array_1230543
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr) // we can also write auto but it is better to define data type explicitly
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> temp(n); // to reserve the memory
    int i = 0;           // we can directly start assigning memory of temp as it is already
                         // reserved (we can't do similar in case of array)
    k = k % n;           // if k > size of array then it reduces k less than n and no change in ans
                         // else we can add every where %n with k
    // while (i < k)
    // {
    //     temp[n - (k - i)] = arr[i];
    //     i++;
    // }
    // while (i >= k && i < n)
    // {
    //     temp[(i - k)] = arr[i];
    //     i++;
    // }
    for (; i < n; i++)
    {
        if (i < k)
        {
            temp[n - (k - i)] = arr[i];
            i++;
        }
        if (i >= k && i < n)
        {
            temp[(i - k)] = arr[i];
            i++;
        }
    }
    arr = temp;
    return arr;
}

int main()
{
    vector<int> array = {1, 2};
    rotateArray(array, 1);
    printArray(array);
    return 0;
}