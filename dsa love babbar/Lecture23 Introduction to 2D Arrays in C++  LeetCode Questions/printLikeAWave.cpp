#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int cols = 0; cols < mCols; cols++)
    {
        if (cols & 1) //->odd col bottom to top
        {
            for (int rows = nRows - 1; rows >= 0; rows--)
            {
                ans.push_back(arr[rows][cols]);
            }
        }
        else // -> even col
        {
            for (int rows = 0; rows < nRows; rows++)
            {
                ans.push_back(arr[rows][cols]);
            }
        }
    }
    return ans;
}

void printVec(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int M, N;
    cout << "Enter the rows in the matrix : " << endl;
    cin >> N;
    cout << "Enter the columns in the matrix : " << endl;
    vector<vector<int>> arr;
    for (int rows = 0; rows < N; rows++)
    {
        for (int cols = 0; cols < M; cols++)
        {
            cout << arr[rows][cols] << " ";
        }
        cout << endl;
    }

    // now printing like a wave
    vector<int> Ans = wavePrint(arr, N, M);
    printVec(Ans);
    return 0;
}