/*
find unique element in an array
where it has N = 2m + 1 size
m elements are occuring twice and 1 element occuring  once
find that element
*/

#include <iostream>
using namespace std;

int return_unique(int *arr, int n)
{
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
        // suppose that array is {a, b, c, d, a, b, c} then final expression will be 
        // a^b^c^d^a^b^c = a^a^b^b^c^c^d = 0^d = d as ^ follows commutative law
        // this is XOR operation 
        // It returns 0 when done between same numbers
        // and 0 ^ num = num
    }
    return ans;
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
 // printing the final answer
    cout << return_unique(array, size) << endl;

    return 0;
}