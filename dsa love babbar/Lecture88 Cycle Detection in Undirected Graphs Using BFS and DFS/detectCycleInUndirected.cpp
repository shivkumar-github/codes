// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	// Function to detect cycle in an undirected graph.
	// using bfs traversal
	bool solveUsingBFS(int V, vector<int> adj[], vector<bool> &visited, int source)
	{
		queue<int> q;
		q.push(source);
		vector<int> parent(V);
		while (!q.empty())
		{
			int crnd = q.front();
			q.pop();
			visited[crnd] = true;
			for (auto neighbour : adj[crnd])
			{
				if (visited[neighbour] && neighbour != parent[crnd]) // if this neighbouring node is already visited and not the parent of current node then the cycle is present
				{
					return true;
				}
				else if (!visited[neighbour]) // else if node not visited yet
				{
					q.push(neighbour);
					parent[neighbour] = crnd;
				}
			}
		}
		return false;
	}
	// using bfs Time Complexity - O(E+V)
	// O(V) extra space as adjacency list is already given and V space for queue

	bool solveUsingDFS(int V, vector<int> adj[], vector<bool> &visited, int source)
	{
		stack<int> st;
		st.push(source);
		vector<int> parent(V);
		while (!st.empty())
		{
			int crnd = st.top();
			st.pop();
			visited[crnd] = true;
			for (auto neighbour : adj[crnd])
			{
				if (visited[neighbour] && neighbour != parent[crnd])// if this neighbouring node is already visited and not the parent of current node then the cycle is present
				{
					return true;
				}
				else if (!visited[neighbour])
				{
					st.push(neighbour);
					parent[neighbour] = crnd;
				}
			}
		}
		return false;
	}
	// Time Complexity for dfs - O(E+V)
	// space Complexity - O(V) for stack

	bool isCycle(int V, vector<int> adj[])
	{
		vector<bool> visited(V, false);
		for (int i = 0; i < V; i++) // for disconnected graph
		{
			if (visited[i])
				continue;
			// bool ans = solveUsingBFS(V, adj, visited, i);
			bool ans = solveUsingDFS(V, adj, visited, i);
			if (ans == true)
				return true;
		}
		return false;
	}
};

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
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}
