#include <bits/stdc++.h>
using namespace std;

/*
	1. Bellman-Ford algorithm helps to find the distance of all nodes from a source node,
	especially in cases where the edges in the graph are negative. Unlike algorithms like
	Dijkstra's, which fail with negative edges and cannot handle negative cycles, Bellman-Ford
	can detect negative cycles and find shortest paths in graphs with negative weights.

	2. Why N-1 times? - Because the path between any nodes can be of a maximum of N-1 edges
	(passing through all the remaining N-2 nodes), where N is the number of nodes in the graph.

	3. Why iterating over the edges? - We iterate over the edges to find the shortest path.
	The k-th traversal over the edges ensures that all paths containing k-1 nodes between the source
	and destination are considered. Thus, iterating for N-1 times covers the maximum possible path length
	(which can contain N-2 nodes in between).

	4. The k-th traversal over the edges gives all paths that contain k-1 nodes between source and destination nodes.
	Therefore, we iterate for N-1 times to ensure the algorithm covers the maximum possible path length.
*/

// Function to implement the Bellman-Ford algorithm
vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges)
{
	vector<int> dist(n + 1, INT_MAX); // considering graph with 1-based indexing
	dist[src] = 0;

	// Traverse over all edges for N-1 times
	for (int i = 1; i <= n - 1; i++)
	{
		for (auto it : edges)
		{
			int u = it[0];
			int v = it[1];
			int w = it[2];

			// Relaxation step: update the distance to vertex v
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	// Check for negative cycle
	bool flag = false;
	for (auto it : edges)
	{
		int u = it[0];
		int v = it[1];
		int w = it[2];

		// If further relaxation is possible, then a negative cycle exists
		if (dist[u] != INT_MAX && dist[u] + w < dist[v])
		{
			flag = true;
			break;
		}
	}

	// If any distance is updated during the N-th traversal, then the graph contains a negative cycle
	return flag ? vector<int>() : dist;
}
/*
Time Complexity - O(E*V) where E is the number of edges and V is the number of nodes in the graph.
Space Complexity - O(V) for the distance array.
*/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges;
	int M = m;
	while (M--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	vector<int> ans = bellmanFord(n, m, 1, edges);

	if (!ans.empty())
	{
		for (int i = 1; i <= n; i++)
		{ // considering graph with 1-based indexing
			if (ans[i] == INT_MAX)
			{
				cout << "INF "; // Print "INF" for unreachable nodes
			}
			else
			{
				cout << ans[i] << " ";
			}
		}
	}
	else
	{
		cout << "The graph contains a negative cycle, hence cannot find the shortest distance from the source node.";
	}
	cout << endl;
	return 0;
}
