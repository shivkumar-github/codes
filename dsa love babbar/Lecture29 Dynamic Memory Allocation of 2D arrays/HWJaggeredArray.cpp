/*
home work creating jaggered array
*/

#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout << "Enter number of rows : " << endl;
    cin >> rows;
    int **arr = new int *[rows];

    // storing number of colomns in another array so as to use them later (the array should be also created dynamically to store number of colomns in each row)
    int *storeCols = new int[rows];

    // creating each row with variable number of colomns
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter number of colomns for " << i + 1 << " row -> " << endl;
        cin >> storeCols[i];
        arr[i] = new int[storeCols[i]];
    }

    // accepting the array 
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < storeCols[i]; k++)
        {
            cin >> arr[i][k];
        }
    }

    // printing the array
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < storeCols[i]; k++)
        {
            cout << arr[i][k] << "\t";
        }
        cout << endl;
    }

    return 0;
}