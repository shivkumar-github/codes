#include <iostream>
using namespace std;

void move0s(int arr[], int n)
{
    int indexnon0s = 0; // keeps the track of index where the non zero element should be placed
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[indexnon0s++]);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {2, 0, 1, 3, 0, 0, 0};
    move0s(array, 7);
    printArray(array, 7);
    return 0;
}
