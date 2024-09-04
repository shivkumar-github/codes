/*
sort 0s, 1s, 2s
*/

#include <iostream>
using namespace std;

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// pehle 0 aur non zero(ek aur do) ko alag karenge
void sort_0s_and_1s_2s(int *arr, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (arr[left] == 0)
        {
            left++;
        }
        while (arr[right] == 1 || arr[right] == 2)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
}

void sort_1s_and_2s(int *arr, int n)
{
    int last0 = 0;
    for (int i = 0; arr[i] == 0; i++)
    {
        last0++;
    }

    int left = last0 + 1, right = n - 1; // aab 1s aur 2s ko sort karte vakt left ki value last 0 ki postion se 1 jyada hogi
    while (left < right)
    {
        while (arr[left] == 1)
        {
            left++;
        }
        while (arr[right] == 2)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
}

void sort_0s_and_1s_and_2s(int *arr, int n)
{
    sort_0s_and_1s_2s(arr, n);
    // fir non zeros(ek aur do ko bhi alag alag karenge)
    sort_1s_and_2s(arr, n);
}

int main()
{
    int array[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    sort_0s_and_1s_and_2s(array, 9);
    print_array(array, 9);
    return 0;
}