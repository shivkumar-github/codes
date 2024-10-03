//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Note :- look bridges before doing articulation points
    void dfs(int crnd, int parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> adj[], vector<bool> &ap, int &timer)
    {
        visited[crnd] = true;
        disc[crnd] = low[crnd] = timer++;
        int child = 0;

        for (auto nbr : adj[crnd])
        {
            if (nbr == parent)
                continue;

            else if (!visited[nbr])
            { // if not visited then continue bfs
                dfs(nbr, crnd, disc, low, visited, adj, ap, timer);
                low[crnd] = min(low[crnd], low[nbr]);
                // check if ap or not
                if (low[nbr] >= disc[crnd] && parent != -1) // basically if any of the nbr of the crnd is unreachable when that node is removed then the crnd is articulation point. And this condition ensures that the nbr is only reachable through the crnd only else it will be unreachable and hence making an extra component hence a articulation point.
                {
                    ap[crnd] = true;
                }
                child++;
            }
            else
            { // back edge
                low[crnd] = min(low[crnd], disc[nbr]); // if we take low of nbr instead of disc then it will give wrong results as low might be a node where we can reach through the nbr so removing nbr will make the node unreachable but it will still show that the node is still reachable (look for example for better understanding.)
            }
        }
        if (parent == -1 && child > 1)
            ap[crnd] = true;
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        int timer = 0;
        vector<int> low(V);
        vector<int> disc(V);
        vector<bool> visited(V);
        vector<bool> ap(V);
        for (int i = 0; i < V; i++)
        {
            low[i] = -1;
            disc[i] = -1;
            visited[i] = false;
            ap[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, disc, low, visited, adj, ap, timer);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (ap[i])
                ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        if (ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends