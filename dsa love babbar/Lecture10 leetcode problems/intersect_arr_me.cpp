/*
find intersection of two arrays
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

void print_intersection(int *arr1, int n1, int *arr2, int n2)
{
    int intersection_array[1000];
    int iterator_for_intersection_array = 0;
    for (int i = 0; i < n1; i++)
    {
        // finding if there is any match of element in first array in second array
        bool anymatch = 0;
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                anymatch = 1;
            }
        }
        // if there is any match then i.e. the element is present in both the arrays then check if it is already present in intersection_array
        if (anymatch == 1)
        {
            bool anymatch_in_intersection_array = 0;
            for (int k = 0; k < iterator_for_intersection_array; k++)
            {
                if (intersection_array[k] == arr1[i])
                {
                    anymatch_in_intersection_array = 1;
                }
            }

            // if it is not already present in intersection array then insert it in intersection array ==> this is to avoid double occurance of an element in the intersection array
            if (anymatch_in_intersection_array == 0)
            {
                intersection_array[iterator_for_intersection_array] = arr1[i];
                iterator_for_intersection_array++;
            }
        }
    }

    // print that array using print_array function
    cout << "Intersection of two arrays is : " << endl;
    print_array(intersection_array, iterator_for_intersection_array);
}// time complexity = > O(nm) not good 

int main()
{
    // creating and accepting arrays
    int array1[1000], size1;
    int array2[1000], size2;
    cout << "Enter the size of first array : " << endl;
    cin >> size1;
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter array1[" << i << "]" << endl;
        cin >> array1[i];
    }
    cout << "Enter the size of second array : " << endl;
    cin >> size2;
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter array2[" << i << "]" << endl;
        cin >> array2[i];
    }

    // calling the function which will find intersection of two arrays
    print_intersection(array1, size1, array2, size2);

    return 0;
}