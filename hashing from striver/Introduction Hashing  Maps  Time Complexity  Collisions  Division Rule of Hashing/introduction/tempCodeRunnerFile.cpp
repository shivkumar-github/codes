/*

*/

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
        int mid = s + (e - s) / 2;
        int len1 = mid + 1 - s;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        for (int i = 0; i < len1; i++)
        {
                first[i] = arr[s + i];
        }
        for (int i = 0; i < len2; i++)
        {
                second[i] = arr[mid + 1 + i];
        }

        int ind1 = 0, ind2=0, mainArrInd =0;
        while (ind1 < len1 && ind2 > len2)
        {
                if (first[ind1] > second[ind2])
                {
                        arr[mainArrInd++] = second[ind2++];
                }
                else{
                        arr[mainArrInd++] = first[ind1++];
                }
        }
        while (ind1<len1)
        {
                arr[mainArrInd++] = first[ind1];
        }
        while (ind2<len2)
        {
                arr[mainArrInd++] = second[ind2++];
        }
        delete first;
        delete second;
}

void mergesort(int *arr, int s, int e)
{
        if (s >= e)
        {
                return;
        }
        int mid = s + (e - s) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);
        merge(arr, s, e);
}

int main()
{
        int arr[5] = {2, 5, 7, 99, 12};
        int n = sizeof(arr) / sizeof(arr[0]);
        mergesort(arr, 0, n - 1);
        return 0;
}