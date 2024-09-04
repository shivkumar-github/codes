/*
Sort 0s and 1s
we have used two pointer approach here
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

void sort_one(int *arr, int n)
{
    int left = 0, right = n - 1;
    while (left < right) // for every process it is neccessary to check if left < right
    {
        while (arr[left] == 0 && left < right)
        {
            left++;
        }
        while (arr[right] == 1 && left < right)
        {
            right--;
        }
        // aab agar yaha tak pohoch gayein hain to
        // these two loops will run upto arr[i] = 1 and arr[j] = 0
        // then we will swap arr[i] and arr[j]
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++, right--;
        }
    }
}

int main()
{
    int array[8] = {1, 1, 0, 0, 0, 0, 1, 0};
    sort_one(array, 8);
    print_array(array, 8);
    return 0;
}