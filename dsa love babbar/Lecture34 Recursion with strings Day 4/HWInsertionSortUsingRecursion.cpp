/*
perform insertion sort using recursion
*/

#include <iostream>
using namespace std;

void PerformSingleInsertion(int arr[], int n, int index = 1)
{
    if (index <= 0)
        return;

    if (arr[index] < arr[index - 1])
    {
        swap(arr[index], arr[index - 1]);
        index = index - 1;
        PerformSingleInsertion(arr, n, index);
    }

    // else kuch mat karo
}
 // our codes are correct just implementation is different
void insertionSort(int arr[], int n, int index = 1)
{
    if (index >= n)
        return;

    // doing single pass each time
    PerformSingleInsertion(arr, n, index);

    // recursive call
    insertionSort(arr, n, ++index);
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {11, 1, 0, 100, 1000};
    insertionSort(arr, 5);
    printArray(arr, 5);
    return 0;
}