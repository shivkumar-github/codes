/*
//important steps in any traversal
// to mark the target as soon as it is executed
// where ever we are pushing elements we must check whether it is visited or not
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// using recursive dfs
void prepareAdjList(vector<vector<int>> &adjList, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
}

void dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &ans, int u)
{
    ans.push_back(u);
    visited[u] = true;
    for (int i = 0; i < adjList[u].size(); i++)
    {
        int el = adjList[u][i];
        if (!visited[el])
        {
            dfs(adjList, visited, ans, el);
        }
    }
}

// using iterative dfs(stack)
void dfs2(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &ans, int u)
{
    stack<int> st;
    st.push(u);
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        ans.push_back(curr);
        for (int i = 0; i < adjList[curr].size(); i++)
        {
            int el = adjList[curr][i];
            if (!visited[el])
            {
                st.push(el);
                visited[el] = true;
            }
        }
    }
}

vector<int> dfsTraversal(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(n);
    vector<int> ans;
    prepareAdjList(adjList, edges);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) // for disconnected graph
    {
        if (!visited[i])
            dfs2(adjList, visited, ans, i);
    }
    return ans;
}

int main()
{
    // different test cases
    vector<vector<int>> adj = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5}, {3, 6}, {4, 7}, {5, 7}, {6, 7}}; // 0 1 4 7 2 5 3 6
    // vector<vector<int>> adj = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5}, {3, 6}, {4, 7}, {5, 7}};// 0 1 4 7 2 5 3 6
    int n = 8;
    vector<int> ans = dfsTraversal(n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}