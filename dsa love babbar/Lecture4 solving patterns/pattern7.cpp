/*
printing the pattern
A
BC
CDE
DEFG
*/

#include <iostream>
using namespace std;

int main()
{
    int dim;
    cout << "Enter the number of dimensions for character pattern : " << endl;
    cin >> dim;

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = ('A' + (i - 1) + (j - 1));
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}