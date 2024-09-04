/*
Leet code
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

#include <iostream>
#include <vector>
using namespace std;
// approach just like book allocation problem .... 
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int mC = matrix[0].size();
        int mR = matrix.size();
        int iRow = 0;              // why ==> because we are going down and left due to updations in while loop so we have to choose a element which have whole the matrix to its down(1st row) and left(last col)
        int iCol = mC -1 ;
        int element = matrix[iRow][iCol];

        while (iCol>=0 && iRow <= mR-1)
        {
            element = matrix[iRow][iCol];
            cout << element << endl;
            if (element == target)
            {
                return 1;
            }
            else if (element < target)
            {
                iRow++;
            }
            else
            {
                iCol--;
            }
        }
        return 0;
    }
};

/*
// babbar's approach 
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex < row && colIndex>=0 ) {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target){
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
        }
        return 0;
    }
};
// I am not getting why this solution is taking less time on leetcode
*/

void acceptMat(vector<vector<int>> &matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int temp = 0;
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }
}

void printMat(vector<vector<int>> &matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    // int size = 0;
    // cout << "Enter the size of matrix : " << endl;
    // cin >> size;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // acceptMat(matrix, size);
    // printMat(matrix, size);
    Solution S1;
    // S1.searchMatrix(matrix, 5);
    bool ans = S1.searchMatrix(matrix, 5);
    cout << ans << endl;
    return 0;
}

// home work any 10 questions of 2d arrays on leetcode



