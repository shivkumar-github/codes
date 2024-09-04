/*
merge sort
For detailed information read gfgs aticle
    It is fastest of all algorithm which we have studied
*/

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy the values in new arrays
    int mainArrInd = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrInd++];
    }

    mainArrInd = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrInd++];
    }

    // merge 2 sorted arrays(have done before in binary sorting questions)
    int index1 = 0;
    int index2 = 0;
    mainArrInd = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrInd++] = first[index1++];
        }
        else
        {
            arr[mainArrInd++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrInd++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrInd++] = second[index2++];
    }

    // delete and free up the memory
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    { // without equal to, function will keep itself calling when s = e = 0 infinitely due to line jisme hum left wala part sort kar rahe hain
        return;
    }

    int mid = s + (e - s) / 2;

    // left part sort karna hai
    mergeSort(arr, s, mid);

    // right part sort karna hai

    mergeSort(arr, mid + 1, e);

    // merge ()
    merge(arr, s, e);
}
/*
Complexities
    ->> Time Complexity
        - O(nlog n)
         (how ->> visit https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-merge-sort/)

    ->> Space Complexity
        - O(n) as the size of temparory array used to store elements is equal to size of input array
*/

int main()
{
    int arr[] = {397, 461, 116, 405, 100, 137, 181, 199, 33, 388, 85, 241, 18, 7, 171, 242, 383, 250, 24, 259, 106, 122, 96, 297, 417, 179, 179, 80, 59, 78, 251, 8, 230, 82, 496, 179, 177, 254, 400, 285, 66, 94, 109, 173, 244, 430, 15, 169, 56, 192, 474, 423, 249, 152, 487, 145, 447, 78, 18, 130, 417, 375, 292};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}