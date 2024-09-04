/*
perform selection sort using recursion
*/

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int index = 0)
{
    if(index >= n-1)// is this correct or it should be 
    return;
    int minIndex = index;
    for (int i = index; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    swap(arr[minIndex],arr[index]);
    selectionSort(arr,n,++index);
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
    int arr[6] = {2, 1, 23, 0, 100, 11};
    selectionSort(arr, 6);
    printArray(arr, 6);
    return 0;
}