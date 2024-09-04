#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
            k++;
        }
        cout << endl;
    }

    return 0;
}