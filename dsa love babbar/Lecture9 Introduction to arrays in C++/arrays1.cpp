/*
some special conditions of arrays
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //
    int array1[10] = {1, 2, 3, 4};
    for (int i = 0; i < 10; i++)
    {
        cout << "array1[" << i << "] = " << array1[i] << endl;
    }
    cout << endl;

    //
    int array2[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        cout << "array2[" << i << "] = " << array2[i] << endl;
    }
    cout << endl;

    //

    int array3[10];
    fill(begin(array3), end(array3), 2);
    // similarly we can do this to strings using some another function
    for (int i = 0; i < 10; i++)
    {
        cout << "array3[" << i << "] = " << array3[i] << endl;
    }
    cout << endl;

    return 0;
}