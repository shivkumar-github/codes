/*
Bubble sort:-

(bubble => to move => here we move smaller element every time by swapping)

In sorting array in non-decreasing manner,
we can say that in i th round i th last maximum element is placed at it's position in sorted array
for example
{1,7,2,3,9,5}
1. after 1st round first maximum element i.e. 9 will be placed at it's position in sorted array (at index = 5)
2. after 2nd round second maximum element i.e. 7 will be placed at it's position in sorted array (at index = 4)

=>
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) //
        {
            if (arr[j + 1] < arr[j]) // standard conditions for all sorting
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        // if not swapped once that means every element after an element is greater than that element i.e. array is already sorted
        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> array = {14, 10, 9, 7, 6, 1};
    bubbleSort(array, array.size());
    printArray(array);
    return 0;
}