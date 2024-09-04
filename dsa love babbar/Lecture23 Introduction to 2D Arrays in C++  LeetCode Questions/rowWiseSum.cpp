#include <iostream>
using namespace std;

void rowWiseSum(int array[][3], int n, int m)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int k = 0; k < 3; k++)
        {
            sum += array[i][k];
        }
        cout << sum << endl;
    }
}

void printColWiseSum(int array[][3], int n, int m)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int k = 0; k < 3; k++)
        {
            sum += array[k][i];
        }
        cout << sum << endl;
    }
}


int main()
{
    int array[3][3];
    cout << "Enter your array : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> array[i][j];
        }
    }
    cout << "Printing the row wise sum : " << endl;
    rowWiseSum(array, 3, 3);

    cout << "Printing the column wise sum : " << endl;
    printColWiseSum(array,3,3);
 

return 0;
}