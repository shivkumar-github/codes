/*
printing the pattern
1234554321
1234**4321
123****321
12******21
1********1
*/

#include <iostream>
using namespace std;

int main()
{
    int dim;
    cout << "Enter the dimension of the pattern : " << endl;
    cin >> dim;
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim - (i - 1); j++)
        {
            cout << j;
        }
        for (int k = 1; k <= (i - 1); k++)
        {
            cout << "**";
        }
        for (int l = dim - (i - 1); l >= 1; l--)
        {
            cout << l;
        }
        cout << endl;
    }
    return 0;
}