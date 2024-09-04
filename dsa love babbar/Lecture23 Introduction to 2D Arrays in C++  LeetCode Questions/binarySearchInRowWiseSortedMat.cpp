/*
Leet Code

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int row = matrix.size();
    int col = matrix[0].size();
    int start = 0;
    int end = row * col;
    int mid = (start + end) / 2;
    while (start >= end) // why it is equal => for the cases where our search case is narrowed to a single element and then start will be equal to end
    {
      int element = matrix[mid / col][mid / row]; // mid ko agar col se divide karenge to mid ka row ayega aur agar mid ko row se divide karnge to mid ka column ayega
      if (element == target)
      {
        return 1;
      }
      else if (element > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
      mid = (start + end) / 2;
    }
    return 0;
  }
};

int main()
{

  return 0;
}