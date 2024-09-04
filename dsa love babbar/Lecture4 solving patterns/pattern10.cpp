/*
printing the pattern
   1
  121
 32123
4321234

dim=4
*/

#include <iostream>
using namespace std;

int main()
{
    int dim;
    cout << "Enter the dimnesion of pattern : " << endl;
    cin >> dim;

    for (int i = 1; i <= dim; i++)
    {   
        // loop for spaces
        for (int j = 1; j <= (dim - i); j++)
        {
            cout << "\t";
        }

        // loops for numbers
        for (int k = 1; k <= i; k++)
        {
            cout << k << "\t";
        }
        for (int l = (i - 1); l >= 1; l--)
        {
            cout << l << "\t";
        }
        cout << endl;
    }
    return 0;
}
