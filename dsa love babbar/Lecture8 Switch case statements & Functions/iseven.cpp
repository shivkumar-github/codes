/*
create a function which checks if given number is even or not
*/

#include <iostream>
using namespace std;

bool checkeven(int n)
{
    if (n & 1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    if (checkeven(num))
    {
        cout << "The number is even." << endl;
    }
    else
        cout << "The number is odd." << endl;
    return 0;
}