/*
coding nijas
https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
        // according to the question the edges contains the nodes which have an edge between them
        vector<int> ans[n];
        // ans array will store all adjacency nodes corresponding on indices
        for (int i = 0; i < m; i++)
        {
                int u = edges[i][0];
                int v = edges[i][1];
                ans[u].push_back(v);
                ans[v].push_back(u);
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
                adj[i].push_back(i);

                // entering neighbours
                for (int j = 0; j < ans[i].size(); j++)
                {
                        adj[i].push_back(ans[i][j]);
                }
        }

        return adj;
} // I think time complexity = O(n^2)  and also space complexity = O(n^2) similar to space complexity (in wosrt case when all nodes are connected to another nodes)the second for loop wil have a dominant time complexity of O(n * (n-1)) = O(n^2)
// for space complexity vector of vectors, adj has n vectors each in the worst case (when one node is connected to all other nodes) each vector may store n values (n-1 connected nodes and 1 itself), therefore space complexities = O(n*n) = O(n^2)

int main()
{

        return 0;
}