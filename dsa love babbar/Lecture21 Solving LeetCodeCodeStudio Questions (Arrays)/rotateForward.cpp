/*
Question on leetcode
// https://leetcode.com/problems/rotate-array/description/
Rotate an array by k in forward direction
for example:=
array[5] = {1, 2, 3, 4, 5} k=2 => {4, 5, 1, 2, 3}
*/
#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &Vec)
{
    for (int i = 0; i < Vec.size(); i++)
    {
        cout << Vec[i] << " ";
    }
    cout << endl;
}

void rotateForward(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> temp(n); // to reserve the memory
    int i = 0;           // we can directly start assignin memory of temp as it is already reserved (we can't do similar in case of array)
    while (i < n)
    {
        temp[(i + k) % n] = arr[i];
        i++;
    }
    arr = temp;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    printArray(array);
    rotateForward(array, 2);
    printArray(array);
    return 0;
}
