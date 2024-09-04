/*
A bit of theory about 2D arrays
*/

#include <iostream>
using namespace std;

/*Yadi aap C++ mein int** ka istemal karte hain, to har row ke liye ek alag pointer hota hai jo us row ko point karta hai, aur har ek row ka pointer ek array of integers ko point karta hai.
array is a pointer to pointer
*/

bool search(int array[][4], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] == key)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int array[3][4] = {1,11,111,1111, 2,22,222,2222,3,33,333,3333};

    // we can take input both columnwise and rowwise also

    // // row wise input
    //   for (int rows = 0; rows < 3; i++)
    // {
    //     for (int cols = 0; cols < 4 ; j++)
    //     {
    //         cin >> array[rows][cols];
    //     }

    // }

    // taking input column wise
    // for (int cols = 0; cols < 4; cols++)
    // {
    //     for (int rows = 0; rows < 3; rows++)
    //     {
    //         cin >> array[rows][cols];
    //     }
    // }

    // // printing the array
      cout << "Your 2D array is : " << endl;
    for (int rows = 0; rows< 3; rows++)
    {
        for (int cols = 0; cols < 4; cols++)
        {
            cout << array[rows][cols] << " ";
        }
        cout << endl;
    }

    // searching an element inside an 2D array
    // cout << search(array, 3, 4, 10) << endl;

    return 0;
}