/*
find an array is unique or not
for example
array = {1,1,2,2,2,3,3,3,3}
here no of occurance of each element is different
for example 1 occures 2 times
2 occures 3 times and 3 occures 4 times
i.e. no elment occures same number of times
therefore array is unique

https://leetcode.com/problems/unique-number-of-occurrences/

*/

#include <iostream>
using namespace std;

bool uniqueOccurances(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        // check karo ki koi ek bhi element do bar aya hai kya
        // agar han to main array ke do elements same number of times ayein hai yani array unique nahi hai
        bool is_double = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i] && i != j)
            {
                // is_double=1;
                return false; // agar koi ek bhi do bar aya hai to not unique array
            }
        }
        // if (is_double==1)
        // {
        //     return 0;
        // }
    }
    return true;
}

// function which calculate and store number of occurances of each element and tell if the main array is unique or not using another function
void tell_if_array_unique(int *arr, int n)
{
    // array to store number of occurances of each element
    int array_of_no_of_occurances[1000];
    // index for array which will store number of occurances of each element
    int index_for_array_of_no_of_occurances = 0;

    // loop which will find number of occurances and store them
    for (int i = 0; i < n; i++)
    {
        // bool variable to check if the occurance of the number is previously calculated or not
        bool is_previously_occured = 0;

        // integer to count number of occurances of the number
        int count = 0;

        // loop which will check if the occurance of the number is previously calculated or not
        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                is_previously_occured = 1;
            }
        }

        // if previously counted then skip karo // agar is element ke number of occurances pehle calculate kiye hai to skip kardo
        if (is_previously_occured == 1)
        {
            continue;
        }
        // agar nahi kiye to uske number of occurances ko count karo
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        // aur jo array number of occurances store kar raha hain usme iske number  of occurances store karva do
        array_of_no_of_occurances[index_for_array_of_no_of_occurances] = count;
        index_for_array_of_no_of_occurances++;
    }
    // now we have to check if every element of this array is unique or not
    // for that we have to check if array of unique elements in this array is nothing but this array --> means iska har element sirf ek bar aya ho
    cout << uniqueOccurances(array_of_no_of_occurances, index_for_array_of_no_of_occurances) << endl;
}

int main()
{
    int array[1000];
    int size;
    cout << "Enter the size of array you are going to enter : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter array[" << i << "] : ";
        cin >> array[i];
    }
    tell_if_array_unique(array, size);

    return 0;
}