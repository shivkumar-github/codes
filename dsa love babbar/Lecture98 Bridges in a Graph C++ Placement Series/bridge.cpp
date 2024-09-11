/*
// approach for a single edge - https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// brute force
int isBridge(int V, vector<int> adj[], int c, int d)
{
	vector<int> cvec;
	for (int i : adj[c])
	{
		if (i == d)
			continue;
		cvec.push_back(i);
	}
	vector<int> dvec;
	for (int i : adj[d])
	{
		if (i == c)
			continue;
		dvec.push_back(i);
	}
	adj[c] = cvec;
	adj[d] = dvec;
	// removed edge from the adjacency list
	// perform dfs from any one node to check whether the other node comes in that dfs to see if graph is discoveredonected or not
	vector<bool> visited(V, false);
	stack<int> st;
	visited[c] = true;
	st.push(c);
	bool flag = true;
	while (!st.empty())
	{
		int crnd = st.top();
		st.pop();
		visited[crnd] = true;
		if (crnd == d)
		{
			flag = false;
			break;
		}
		for (auto nbr : adj[crnd])
		{
			if (!visited[nbr])
			{
				st.push(nbr);
			}
		}
	}
	return flag;
}
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{ // METHOD:  2 for every bridge edge
public:
	void dfs(int crnd, int parent, int &timer, vector<int> &discovered, vector<int> &low, vector<vector<int>> &result, vector<int> adj[], vector<bool> &visited)
	{
		visited[crnd] = true;
		low[crnd] = discovered[crnd] = timer++;

		for (auto nbr : adj[crnd])
		{
			// we need to check if any non parent node is visited again
			if (nbr == parent)
				continue;
			if (!visited[nbr])
			{
				// node is not parent and not visited yet so perform dfs and check if it's child node have a back edge
				dfs(nbr,crnd,timer,discovered,low,result,adj,visited);
				low[crnd] = min(low[crnd], low[nbr]);
				if (low[nbr] > discovered[crnd]) // bridge edge
				{
					vector<int> t;
					t.push_back(crnd);
					t.push_back(nbr);
					result.push_back(t);
				}
			}
			else
			{
				// back edge
				low[crnd] = min(low[crnd], discovered[nbr]);
			}
		}
	}

	// Function to find if the given edge is a bridge in graph.
	int isBridge(int V, vector<int> adj[], int c, int d)
	{
		// to store the results we will require a result
		vector<vector<int>> result;
		// we will keep track of two variable for each node one will save the general(discovered) and special value(low) if exists due to the back edge and if back edge exists then all the nodes in that path will have different general and special value(which is time in this case)
		int timer = 0;
		// value of time when the node is discovered
		vector<int> discovered(V);
		// lowest possible value
		vector<int> low(V);
		// we also need to store the visited to perform the dfs
		vector<bool> visited(V);
		for (int i = 0; i < V;i++){
			visited[i] = false;
			low[i] = -1;
			discovered[i] = -1;
		}
			// we will also need a parent variable to keep track of parent
			int parent = -1;

		// dfs traversal
		for (int i = 0; i < V; i++)
		{
			if (!visited[i])
			{
				dfs(i, parent, timer, discovered, low, result, adj, visited);
			}
		}
		for (auto it : result)
		{
			// cout << it[0] << it[1] << endl << endl;
			if ((it[0] == c && it[1] == d) || (it[0] == d && it[1] == c))
				return true;
		}
		return false;
	}
};
//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;
		vector<int> adj[V];
		int i = 0;
		while (i++ < E)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int c, d;
		cin >> c >> d;

		Solution obj;
		cout << obj.isBridge(V, adj, c, d) << "\n";
	}

	return 0;
}

// } Driver Code Ends