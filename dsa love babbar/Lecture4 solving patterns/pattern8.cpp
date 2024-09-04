/*
printing the pattern
D
CD
BCD
ABCD
*/

#include <iostream>
using namespace std;

int main()
{
    int dim = 0; // setting default value is a good practice
    cout << "Enter the value of dim of pattern : " << endl;
    cin >> dim;

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = ('A' + (dim - i) + (j - 1));
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}