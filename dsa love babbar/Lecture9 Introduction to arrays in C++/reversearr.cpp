/*
reverse an array
*/

#include <iostream>
using namespace std;


//  my logic
void reversearray(int* arr, int n){
    int reversearr[n];
    for (int i = 0; i < n; i++)
    {
        reversearr[i] = arr[n-i-1];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = reversearr[i];
    }

}

// // logic by babbar bhaiya
// void reversearray(int *arr, int n)
// {
//     int start = 0;
//     int end = n - 1;
//     for (int i = 0; i < n / 2; i++) // we can also do it by running i < n and when start<= end
//     {
//         int temp;
//         temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int array[1000];
    int size;
    cout << "Enter the size of array which you want to reverse: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << (i + 1) << " element." << endl;
        cin >> array[i];
    }
    reversearray(array, size);
    printarray(array, size);
    return 0;
}