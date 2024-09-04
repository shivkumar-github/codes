// 1.5 hrs
// badhiya dimaag lagao
// LeetCode
// https://leetcode.com/problems/rotate-image/
#include <iostream>
#include <vector>
using namespace std;

//https://drive.google.com/file/d/1mNVdbqjwuODDGKP4JGrPr1abVNEnP5Mz/view?usp=sharing
// each vertex on quad (i.e. 4 vertices) move their position with each other and each section has these types of quadrilaterals
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size(); // square matrix
        for (int secNum = 0; secNum < n / 2; secNum++)
        {
            for (int quadNum = 0; quadNum < n - 1 - 2 * secNum; quadNum++) // try to build logic with general example
            {
                int guest = matrix[n - 1 - quadNum - secNum][secNum];
                int rHouseer = secNum;
                int cHouser = quadNum + secNum;
                for (int i = 0; i < 4; i++)
                {

                    // int rGuest = n - 1 - cHouser;
                    // int cGuest = rHouseer;
                    int oldHouser = matrix[rHouseer][cHouser];
                    matrix[rHouseer][cHouser] = guest;
                    // purana houser guest ban gaya
                    guest = oldHouser;
                    // naye houser ko dhundo
                    int tempStore = rHouseer;
                    rHouseer = cHouser;
                    cHouser = n - 1 - tempStore;
                }
            }
        }
    }
};


void acceptMat(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMat(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    // int n = 0;
    // cout << "Enter dimension of your matrix : " << endl;
    // cin >> n;
    // int size = n*n;
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    // cout << "size = " << matrix.size();
    // cout << "Now Enter your matrix : " << endl;
    // acceptMat(matrix);

    printMat(matrix);
    cout << endl;

    Solution S1;
    S1.rotate(matrix);
    printMat(matrix);

    return 0;
}

/*
factors that I skipped
However, there is a small issue in the code. The inner loop should run for n - 1 -secNum times instead of n - 1. This is because the last element in each row is already covered in the previous iteration. The correct loop condition should be quadNum < n - 1 - secNum.
secNum < n / 2 instead of secNum <= n / 2
Upon closer inspection, I found a small mistake in the inner loop condition. The condition quadNum < n - 1 - secNum may lead to skipping the last element in the last row of each layer. To fix this, you should adjust the inner loop condition to quadNum < n - 1 - 2 * secNum to ensure that all elements in the current layer are processed.
is our approach good means trying out with specific examples rather than a general example -  > no
*/