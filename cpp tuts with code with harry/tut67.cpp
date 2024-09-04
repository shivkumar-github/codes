/*
using function templates
*/

#include <iostream>
using namespace std;

template <class T>
T myfunc(T a, T b)
{
    return (a + b) / 2;
}
int main()
{
    cout << myfunc(2, 4) << endl;
    cout << myfunc(3.2, 1.2) << endl;
    return 0;
}