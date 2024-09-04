/*
Function Objects in C++
*/

#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    // Function Objects (Functor): Functions wrapped in a class so that
    // it availabel like an object
    int array[] = {1, 32, 4, 2, 54, 77, 3};
    // sort(array, array + 5); // array+5 ke aage valon ko sort nahi karega
    sort(array, array+7, greater<int>()); // sorts the array in reverse order

    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

// completed C++ at 29-12-2023