// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
		int sum = 0;
		vector<bool> mst(V, false);
		// we don't need to maintain parent while calulating only sum of edges but if asked to return the mst then we have to maintain the parent array also.
		minHeap.push({0, 0});
		while (!minHeap.empty())
		{
			int w = minHeap.top().first;
			int u = minHeap.top().second;
			minHeap.pop();
			if (mst[u])
				continue; // DOUBT: why continue and not
						  // 			if(!mst[u]), see at end of the code(to avoid repeated pushing of nodes with same edges weight)
			sum += w;
			mst[u] = true;
			for (auto it : adj[u])
			{
				int neigh = it[0];
				int neigh_weight = it[1];
				if (!mst[neigh])
				{
					minHeap.push({neigh_weight, neigh});
				}
			}
		}
		return sum;
	}
};
// Time Complexity - O(ElogV) - As each nodes is visited once and for push and pop in pq the worst case time complexity (when all the nodes )
// Space Complexity - O(V+E) as minHeap takes up space E and array to store if node is included in mst or not is V so space complexity becomes O(E+V)
// https://stackoverflow.com/questions/20430740/time-complexity-of-prims-algorithm
//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int>> adj[V];
		int i = 0;
		while (i++ < E)
		{
			int u, v, w;
			cin >> u >> v >> w;
			vector<int> t1, t2;
			t1.push_back(v);
			t1.push_back(w);
			adj[u].push_back(t1);
			t2.push_back(u);
			t2.push_back(w);
			adj[v].push_back(t2);
		}

		Solution obj;
		cout << obj.spanningTree(V, adj) << "\n";
	}

	return 0;
}

// } Driver Code Ends

/*
When the node is already included in the mst it is not sufficient to avoid only the addition of that edge to anwer.
We also have to take care that the neighbouring nodes of that node should not be added again to priority queue otherwise it will lead to greater time complexity.
for ex
see the image
*/