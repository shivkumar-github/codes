/*
    Linear search
*/

#include <iostream>
using namespace std;

bool search(int *arr, int size, int searchfor)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == searchfor)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int array[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    // we want to tell whether 1 is present or not
    cout << search(array, 10, 1);

    return 0;
}