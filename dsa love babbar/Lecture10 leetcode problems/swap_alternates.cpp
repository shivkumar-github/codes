/*
swap alternate elements of an array
for ex array[] = {1,2,3,4,5}
then after alternate swapping
array[] = {2,1,4,3,5}
*/

#include <iostream>
using namespace std;

// function to print the array
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// swapping the alternate elements of an array
void swap_alternate(int *arr, int n)
{
    for (int i = 0; i + 1 < n; i += 2) // to jump to second pair we have to i += 2 and i+1 is greater than i therefore we have to check for value of i+1 < size of array
    {
        // int temp = arr[i];
        // arr[i] = arr[i + 1];
        // arr[i + 1] = temp;

        // this also can be done by function
        swap(arr[i], arr[i + 1]);
    }
}
int main()
{
    // accepting the array
    int array[1000];
    int size;
    cout << "Enter the size of array : " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter array[" << (i + 1) << "] : ";
        cin >> array[i];
    }
    // swapping and printing the array
    swap_alternate(array, size);
    print_array(array, size);

    return 0;
}