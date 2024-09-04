#include <iostream>
#include <vector>
using namespace std;

// function to get matrix
void setMat(vector<vector<int>> &grid)
{
    cout << "Enter your matrix -> " << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int k = 0; k < grid[0].size(); k++)
        {
            cin >> grid[i][k];
        }
    }
}

// function to print the matrix
void printMat(vector<vector<int>> &grid)
{
    cout << "Your array is -> " << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int k = 0; k < grid[0].size(); k++)
        {
            cout << grid[i][k] << "\t";
        }
        cout << endl;
    }
}

// function to rotate the array
void rotateArrBy1(vector<int> &array)
{
    int beforval = array[0];
    for (int i = 0; i < array.size() - 1; i++)
    {
        int temp = beforval;
        beforval = array[i + 1];
        array[i + 1] = temp;
    }
    array[0] = beforval; // now temp is last element
}

// function to assign the grid to an array
void assignArrToGrid(vector<int> &array,vector<vector<int>> &grid)
{

    int index = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int k = 0; k < grid[0].size(); k++)
        {
            array[index++] = grid[i][k];
        }
    }
}

// function to assign and return roteted array
vector<int> returnRotateArrOfGrid(vector<vector<int>> &grid)
{
    vector<int> array(grid.size() * grid[0].size());
    assignArrToGrid(array,grid);
    rotateArrBy1(array);
    return array;
}

class Solution
{
    friend void setMat(vector<vector<int>> &grid);
    friend void printMat(vector<vector<int>> &grid);
    friend void rotateArrBy1(vector<vector<int>> &grid);
    friend vector<int> returnRotateArrOfGrid(vector<vector<int>> &grid);


public:
    // approach 1
    // vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    // {

    //     vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
    //     int mRows = grid.size();
    //     int mCols = grid[0].size();
    //     k = k % (mCols * mRows);
    //     for (int l = 0; l < k; l++)
    //     {
    //         for (int i = 0; i < mRows; i++)
    //         {
    //             for (int j = 0; j < mCols; j++)
    //             {
    //                 // last column elements
    //                 if (j == mCols - 1)
    //                 {
    //                     // when element is at last row and last column
    //                     ans[(i + 1) % mRows][0] = grid[i][j];
    //                 }
    //                 // other than last columns
    //                 else
    //                 {
    //                     ans[i][j + 1] = grid[i][j];
    //                 }
    //             }
    //         }
    //         // updating the grid after every shift
    //         grid = ans;
    //     }

    //     return grid;
    // }

    // approach 2
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        // declaring some variables
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        // storing grid in an 1D array and rotating that array to assign that array to grid later --> by pattern of shifting
        vector<int> RotetedArrayOfGrid = returnRotateArrOfGrid(grid);
        // assigning values inside the rotated array to the grid
        int index1 = 0;
        for (int i = 0; i < m; i++)
        {
            for (int k = 0; k < n; k++)
            {
                grid[i][k] = RotetedArrayOfGrid[index1++];
                cout << grid[i][k] << endl;
            }
        }
        return grid;
    }
};

int main()
{
    // int rows, cols, k;
    // cout << "Enter rows of your matrix -> " << endl;
    // cin >> rows;
    // cout << "Enter columns of your matrix -> " << endl;
    // cin >> cols;
    // vector<vector<int>> grid(3, vector<int>(3, 0)); // reserving memory
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // gridMat(grid);
    // cout << "Enter value of k -> " << endl;
    // cin >> k;
    printMat(grid);
    Solution S1;
    S1.shiftGrid(grid, 1);
    printMat(grid);

    return 0;
}