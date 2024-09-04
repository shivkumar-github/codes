// https://leetcode.com/problems/unique-paths/
// DOUBT: what about time and space complexity of every problem
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
        void rec(int m, int n, vector<vector<int>> mat, int &cnt, int sr, int sc)
        {
                if (sr == m - 1 && sc == n - 1)
                {
                        cnt++;
                        return;
                }
                if (sr + 1 < m && mat[sr + 1][sc] == 1)
                {
                        rec(m, n, mat, cnt, sr + 1, sc);
                }
                if (sc + 1 < n && mat[sr][sc + 1] == 1)
                {
                        cout << cnt << endl;
                        rec(m, n, mat, cnt, sr, sc + 1);
                }
        }

        int uniquePaths(int m, int n)
        {
                vector<vector<int>> mat;
                for (int i = 0; i < m; i++)
                {
                        vector<int> temp(n, 1);
                        mat.push_back(temp);
                }

                int cnt = 0;
                rec(m, n, mat, cnt, 0, 0);
                return cnt;
        }
};

int main()
{
        int m = 23, n = 12;
        // cin >> m;
        // cin >> n;
        Solution s;
        int ans = s.uniquePaths(m, n);
        cout << ans << endl;
        return 0;
}