/*
coding nijas
https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
        vector<vector<int>> ans(n);

        // at first all element should be inserted in their own array
        // the case of discontinuous graph is also covered by this loop
        for (int i = 0; i < n; i++)
        {
                ans[i].push_back(i);
        }

        // then insert elements which are connected to it
        for (int i = 0; i < m; i++) // also m = edges.size()
        {
                // two nodes which are connected by edge
                int u = edges[i][0];
                int v = edges[i][1];
                ans[u].push_back(v);
                ans[v].push_back(u);
        }
        return ans;
}
// time complexities and space complexities of the codes
// worst case time complexity will be O(max(n, m)) 
// and space complexity same *O(n^2) actual*->> O(m*n) which in worst case will be n*n

int main()
{

        printAdjacency();
        return 0;
}