#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    // compare based on their edges weight
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    // if node is parent of itself then return node else return parent of parent and also update the parent array so as to use path compression
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
    // vector to store mst edges
    vector<vector<int>> MST;
    // cost of mst
    int cost = 0;
    // array to store ultimate parent of each node
    vector<int> parent(n+1); // declaring with n+1 to handle cases with 1 based indexing
    // array to store rank of each node
    vector<int> rank(n+1);

    makeSet(parent, rank, n);
    // Sort the edges array by weight
    sort(edges.begin(), edges.end(), cmp);

    // Now iterate over the edges
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        // If their parents are not equal, adding this edge will not form a cycle
        if (findParent(parent, u) != findParent(parent, v))
        {
            cost += w;
            // add edge to mst
            vector<int> t = {u, v, w};
            MST.push_back(t);
            // Perform the union
            unionSet(u, v, parent, rank); // Pass the original u and v
        }
    }
    // print edges in MST
    cout << "Edges present in MST are : " << endl;
    for (auto it : MST)
    {
        for (int i : it)
            cout << i << " ";
        cout << endl;
    }
    return cost;
}

// Time Complexity - O(mlogm) -(mlogm for sorting the edges vector and for find parent and unionSet O(1)) where m is the number of edges in the graph.
// Space Complexity - O(n)(as for n nodes there will be exactly n-1 edges in the MST) - for storing the edges of MST also O(n) for parent and rank array

int main()
{
    vector<vector<int>> g;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t = {u, v, w};
        g.push_back(t);
    }
    int ans = kruskalMST(n, g);
    cout << ans << endl;
    return 0;
}