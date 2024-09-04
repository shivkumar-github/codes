/*
trying out with vector of vector
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> Myvec(12,3);
    int rows = 3;
    int cols = 3;
    vector<vector<int>> Myvec(rows, vector<int>(cols, 5)); // initialising a vector containg vectors of typ int (2D arrays) with rows each of size cols and each row vector has element 5
    cout << Myvec.size() << endl;
    cout << Myvec[0].size() << endl;
    for (int j = 0; j < Myvec.size(); j++)
    {
        for (auto i = 0; i < Myvec[0].size(); i++)
        {
            cout << Myvec[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}