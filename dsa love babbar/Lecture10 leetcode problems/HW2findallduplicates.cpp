/*
find duplicate elements in an array
this code gives all duplicate elements in an array
but in love babbars video it is said that to find only one element that has occured twice and array contains first n-1 integers
*/

#include <iostream>
using namespace std;

// function to print array
void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function which will print duplicate elements in that array
void printduplicate(int *arr, int n)
{
    // array which will store the duplicate elements
    int array_of_duplicate[1000];
    // index to access that array
    int index_for_array_of_duplicate = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // if there is an duplicate of that element then store it in array of duplicates
            if (arr[i] == arr[j] && i != j)
            {
                array_of_duplicate[index_for_array_of_duplicate] = arr[i];
                index_for_array_of_duplicate++;
            }
        }
    }
    // print array_of_duplicate
    cout << "The duplicate elements in the array are : " << endl;
    printarray(array_of_duplicate, index_for_array_of_duplicate);
}

int main()
{
    int array[1000];
    int size;
    cout << "Enter size of your array : " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter array[" << (i) << "] : " << endl;
        cin >> array[i];
    }

    printduplicate(array, size);

    return 0;
}