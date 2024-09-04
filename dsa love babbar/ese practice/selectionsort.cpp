#include<iostream>
using namespace std;

/* every time we put the minimum element at it's position*/

class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        int minIndex = i;
        // code here such that selectionSort() sorts arr[]
        for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
        return minIndex;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
          for (int i = 0; i < n-1; i++)
        {
            int minIndex = select(arr, i, n);
            swap(arr[i], arr[minIndex]);
        }
    }
}