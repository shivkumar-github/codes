#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int mRows = matrix.size();
        int mCols = matrix[0].size();
        int total =  mRows*mCols;
        vector<int> ans;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = mRows - 1;
        int endingCol = mCols - 1;
        int count = 0;
        while (count <total)
        {
            for (int index = startingCol; index <= endingCol && count <total; index++)
            {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            for (int index = startingRow; index <= endingRow && count <total; index++)
            {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            for (int index = endingCol; index >= startingCol && count <total; index--)
            {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            for (int index = endingRow; index >= startingRow && count <total; index--)
            {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;  
    }
};
// time complexity = O(m*n)
int main(){

    return 0;
}