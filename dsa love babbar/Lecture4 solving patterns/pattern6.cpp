/*
printing the pattern
ABC
BCD
CDE
*/

#include <iostream>
using namespace std;

int main()
{
    int dim;
    cout << "Enter the value of dimension of character matrix : " << endl;
    cin >> dim;
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            char ch = ('A' + (i - 1) + (j - 1));
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}