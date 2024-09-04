/*
Theory Lecture on Selection Sort==>
As it's name suggests, it selects smallest(or largest, depending upon the order)
from the unsorted part of the array
and swaps it with the first unsorted element.

In sorting array in non decreasing manner
we can say in each i th round i th minimum element is placed at its position in sorted array

==> Space Complexity
As we are just creating variables here our space complexity = O(1)

==> Time Complexity
For array containing n elements
1 + 2 + 3 + .... + (n-1) = n(n-1)/2 = n^2/2 - n/2 ==> O(n^2)
=> Best Case -> already sorted -> O(n^2)
=> Worst Case -> non increasing array (4, 3, 2, 1) -> O(n^2)
i.e. Time Complexity is same for worst and best case

==> Use Case
Section Sort might be helpful when size of array or vector is small

Homework =>
==> Stable or unstable algorithm
    It is an unstable algorithm
    [1, 2, 8, 5b, 5a] ==> [1, 2, 8, 5a, 5b]
    In stable algorithm, the relative order of equal elements remains the same in the sorted output as it was in the original input
    i.e.
    [1, 2, 8, 5b, 5a] ==> [1, 2, 8, 5b, 5a]

    In short 1 element ko select karke sort kardo
*/

#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    // vector<int> array = {1, 4, 2, 7, 9, 5, 4, 4, 84, 2, 23, 2, 2, 22, 212, 233,22,45,444};
    vector<int> array = {4, 3, 2, 1};
    // selectionSort(array, 4);
    selectionSort1(array, 4);
    print_array(array, 4);
    return 0;
}