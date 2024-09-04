#include <iostream>
using namespace std;

int count = 0;

int partition(int arr[], int s, int e)
{
        int pivot = arr[s];

        int cnt = 0;
        for (int i = s + 1; i <= e; i++)
        {
                if (arr[i] <= pivot)
                        cnt++;
        }

        // place pivot at right position
        int pivotIndex = s + cnt;
        swap(arr[pivotIndex], arr[s]);

        // left and right wala part smbhal lete h
        int i = s, j = e;

        while (i < pivotIndex && j > pivotIndex)
        {

                while (arr[i] <= pivot) // have to place equal to other wise when equal element is encountered neither i nor j will change
                {
                        i++;
                }

                while (arr[j] > pivot)
                {
                        j--;
                }

                if (i < pivotIndex && j > pivotIndex)
                {
                        swap(arr[i++], arr[j--]);
                }
        }
        return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{

        // base case
        if (s >= e)
                return;

        // partition karen
        int p = partition(arr, s, e);
        // left part sort karo
        quickSort(arr, s, p - 1);

        // right wala part sort karo
        quickSort(arr, p + 1, e);
}

/*
time complexity  => O(n log n) ->> for avg and best case
->> in worst case time complexity ->> O(n^2)
space complexity => O(n)
*/

int main()
{

        // int arr[] = {2, 4, 9, 9, 9, 1, 6 ,9, 9, 9};
        int arr[] = {9, 4, 9, 2, 9, 1, 8, 9, 1};
        int n = sizeof(arr) / sizeof(arr[0]);

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;

        return 0;
}
