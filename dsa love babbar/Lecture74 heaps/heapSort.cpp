/*
heap sort in max heap
aligning the elements in heap in increasing order
    it considers of mainly two steps
    I. swap arr[1] and arr[size]
    II. root node at correct position i.e. heapify
*/

#include <iostream>
using namespace std;
// following 1 based indexing
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (arr[l] > arr[largest] && l <= size)
    {
        largest = l;
    }
    if (arr[r] > arr[largest] && r <= size)
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    while (size >= 2)
    {
        // step 1: swap
        swap(arr[size], arr[1]);
        size--;
        // step 2
        heapify(arr, size, 1);
    }
} // Time Complexity - O(nlogn) (O(n) to build the max heap from the given array and each of n-1 calls to heapify take log n time)
// Space Complexity - O(1) constant extra space

int main()
{
    // following 1 based indexing
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    // heap creation starting from first non leaf node to the root node(nodes from size/2 + 1 to size are already max heap as they are leaf node)
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }

    // heap sort
    heapSort(arr, size);
    cout << "Printing sorted array : " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}