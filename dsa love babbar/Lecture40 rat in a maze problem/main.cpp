// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// code by me and comments by chat gpt

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
        void rec(vector<vector<int>> mat, int n, int sr, int sc, vector<string> &ans, string path)
        {
                // mark the cells to zero for checking if already visited (instead of making new vector for marking)
                mat[sr][sc] = 0;

                // If the destination is reached, add the path to the answer and return
                if (sr == n - 1 && sc == n - 1)
                {
                        ans.push_back(path);
                        return;
                }

                // Explore all possible directions
                // U
                if (sr - 1 >= 0 && mat[sr - 1][sc] == 1)
                {
                        rec(mat, n, sr - 1, sc, ans, path + "U");
                }
                // D
                if (sr + 1 < n && mat[sr + 1][sc] == 1)
                {
                        rec(mat, n, sr + 1, sc, ans, path + "D");
                }
                // L
                if (sc - 1 >= 0 && mat[sr][sc - 1] == 1)
                {
                        rec(mat, n, sr, sc - 1, ans, path + "L");
                }
                // R
                if (sc + 1 < n && mat[sr][sc + 1] == 1)
                {
                        rec(mat, n, sr, sc + 1, ans, path + "R");
                }
        }
        vector<string> findPath(vector<vector<int>> &mat)
        {
                int n = mat.size();
                vector<string> ans;
                if (n == 0 || mat[0][0] == 0)
                {
                        return ans;
                }
                string path = "";
                rec(mat, n, 0, 0, ans, path);
                sort(ans.begin(), ans.end());
                return ans;
        }
};

int main()
{
        return 0;
}