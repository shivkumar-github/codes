/*
perform bubble sort using recursion
*/

#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SingleSort(int *arr, int n, int index = 0) // representing each pass in sort
{
    if (index >= n - 1)
        return;
    if (arr[index] > arr[index + 1])
        swap(arr[index], arr[index + 1]);
    SingleSort(arr, n, ++index);
}

void bubbleSort(int *arr, int n, int index = 0)
{
    if (index >= n - 1)
        return;
    SingleSort(arr, n, 0);
    bubbleSort(arr, n, ++index);
}
// babbar's code is sane just structure is different

int main()
{
    int arr[6] = {14, 10, 9, 7, 6, 1};
    bubbleSort(arr, 6);
    printArray(arr, 6);
    return 0;
}