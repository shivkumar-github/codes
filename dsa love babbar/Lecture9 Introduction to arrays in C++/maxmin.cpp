/*
finding maximum and minimum element of an array
int size;
cin>>size;
int array[size];

bad practice ...instead declare an array with greater size
for array[1000];
*/

#include <iostream>
using namespace std;


// the function which will print the maximum and minimum value in the array
void printminmax(int* arr, int n)
{
    int maximum = INT32_MIN;
    int minimum = INT32_MAX; // by logic
    for (int i = 0; i < n; i++)
    {

        cout << "Enter the " << (i + 1) << " th element of array : " << endl;
        cin >> arr[i];
        // if (arr[i] > maximum)
        // {
        //     maximum = arr[i];
        // }
        maximum = max(maximum, arr[i]);
       
        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }

    // printing the maximum and minimum value
    cout << "The maximum element is : " << maximum << endl;
    cout << "The minimum element is : " << minimum << endl;
}

int main()
{
    int array[1000];
    int size;
    cout << "Enter the size of array you are going to enter : " << endl;
    cin >> size;
    printminmax(array,size);
    return 0;
}
