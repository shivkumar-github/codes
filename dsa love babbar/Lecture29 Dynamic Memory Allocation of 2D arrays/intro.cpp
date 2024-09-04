/*
 Here we will be doing like 
    arr->> 
        int*   --> |        |       |       |       |       |        ->> each pointer consisting of own array and main array consists of those pointers
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |
        int*   --> |        |       |       |       |       |


article of coding ninjas on dynamic memory allocation



*/

#include <iostream>
using namespace std;
int main()
{
    // // creating a symmetric array
    // int n;
    // cin >> n;

    // // creating a 2d array
    // // ek array jo pointers ko store kar raha
    // int **arr = new int *[n];

    // // har ek  stored pointer ko ek integers ke array ke sath point karva do
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = new int[n];
    // }

    // // creation done

    // // taking input
    // for (int i = 0; i < n; i++)
    // {
    //     for (int k = 0; k < n; k++)
    //     {
    //         cin >> arr[i][k];
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int k = 0; k < n; k++)
    //     {
    //         cout <<  arr[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    // // free up the memory

    // // first deleting array of each pointer 
    // for (int i = 0; i < n; i++)
    // {
    //     delete[] arr[i];
    // }

    // // then deleting array of those pointers
    // delete[] arr;
/**********************************************************/

    // creating a non symmetric array
    int rows, cols;
    cin >> rows >> cols;
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols] ;
    }
    
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}