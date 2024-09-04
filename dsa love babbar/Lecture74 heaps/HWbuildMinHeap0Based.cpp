/*
coding ninjas
https://www.codingninjas.com/studio/problems/build-min-heap_1171167

*/

#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (arr[l] < arr[smallest] && l < size)
    {
        smallest = l;
    }
    if (arr[r] < arr[smallest] && r < size)
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}

int main()
{
    vector<int> arr = {12, 10, 9, 6, 15, 17};
    arr = buildMinHeap(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}