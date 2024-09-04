/*
find unique element in an array
this code will find unique elements in an array
*/

#include <iostream>
using namespace std;

// function to print the array
void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function which will find and store unique elements of array in another array array_of_unique
void printunique(int *arr, int n)
{
    int array_of_unique[1000]; // an array to store elements which are unique
    int iterator_for_array_of_unique = 0;
    for (int i = 0; i < n; i++)
    {
        bool anymatch = 0;
        // find if any match
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                anymatch = 1;
                break;
            }
        }

        // if anymatch not found then store it in the array_of_unique
        if (anymatch == 0)
        {
            array_of_unique[iterator_for_array_of_unique] = arr[i];
            iterator_for_array_of_unique++;
        }
    }

    // printing the array consisting of unique elements
    cout << "Unique elements of your array are : " << endl;
    printarray(array_of_unique, iterator_for_array_of_unique);
}

int main()
{
    int array[1000];
    int size;
    cout << "Enter the size of array you are going to enter : " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter array[" << i << "] : ";
        cin >> array[i];
    }
    printunique(array, size);

    return 0;
}