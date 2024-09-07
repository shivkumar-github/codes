/*
A minimum spanning tree (MST) is defined as a spanning tree that has the minimum weight(sum of weights of all edges) among all the possible spanning trees.
coding ninjas - https://www.naukri.com/code360/problems/prim-s-mst_1095633
*/

#include <bits/stdc++.h>
using namespace std;

// METHOD: 1 : Using array(here named ke) to store weight of each edge and searching minimum element in that array (TC - O(V) for finding each minimum element)
vector<pair<pair<int, int>, int>> calculatePrimsMST1(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
	unordered_map<int, list<pair<int, int>>> adj;
	vector<pair<pair<int, int>, int>> result;
	vector<bool> mst(n + 1);
	vector<int> parent(n + 1);
	vector<int> key(n + 1);

	for (auto i : g)
	{
		int u = i.first.first;
		int v = i.first.second;
		int w = i.second;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for (int i = 1; i <= n; i++)
	{
		mst[i] = false;
		key[i] = 1e9;
		parent[i] = -1;
	}

	// intialise the source
	key[1] = 0;
	parent[1] = -1;

	for (int count = 1; count <= n; count++)
	{ // finding minimum for v times so that all nodes will be visited
		int mini_weight = 1e9;
		int u;
		// find minimum nodes from the key which is not visited
		for (int v = 1; v <= n; v++)
		{
			if (!mst[v] && key[v] < mini_weight)
			{
				u = v;
				mini_weight = key[v];
			}
		}
		mst[u] = true; // important to remember where to mark the node true
		// check for adjcent nodes
		for (auto adjNode : adj[u])
		{
			int v = adjNode.first;
			int w = adjNode.second;
			if (!mst[v] && w < key[v])
			{
				// update the parent and key
				parent[v] = u;
				key[v] = w;
			}
		}
	}
	for (int i = 2; i <= n; i++)
		result.push_back({{parent[i], i}, key[i]});

	return result;
}
// Time Complexity - O(V^2)
// Space Complexity - O(V+E) - O(V) for parent, key and mst but O(E+V) for adjacency list

// 	METHOD: 2 Using minHeap (priority queue) will reduce the time required to find the minimum element each time
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
	unordered_map<int, list<pair<int, int>>> adjList;
	vector<pair<pair<int, int>, int>> result;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
	vector<bool> mst(n + 1);
	vector<int> parent(n + 1); // to maintain the parent of every node
	vector<int> key(n + 1);
	// prepare adjacency list
	for (auto i : g)
	{
		int u = i.first.first;
		int v = i.first.second;
		int w = i.second;
		adjList[u].push_back({v, w});
		adjList[v].push_back({u, w});
	}

	for (int i = 1; i <= n; i++)
	{
		mst[i] = false;
		parent[i] = -1;
		key[i] = 1e9;
	}
	key[1] = 0;
	vector<int> first = {key[1], 1, parent[1]};
	minHeap.push(first);
	while (!minHeap.empty())
	{
		vector<int> cr = minHeap.top();
		minHeap.pop();
		int crNode = cr[1];
		int crWeight = cr[0];
		int crParent = cr[2];
		if (mst[crNode])
			continue;
		mst[crNode] = true;
		parent[crNode] = crParent;
		key[crNode] = crWeight;
		for (auto i : adjList[crNode])
		{
			int neighWeight = i.second;
			int neighNode = i.first;
			if (!mst[neighNode])
			{
				vector<int> t = {neighWeight, neighNode, crNode};
				minHeap.push(t);
			}
		}
	}

	// as 1 has no parent starting with 2
	for (int i = 2; i <= n; i++)
		result.push_back({{parent[i], i}, key[i]});

	return result;
}
// Time Complexity - O(ElogV) - As each nodes is visited once and for push and pop in pq the worst case time complexity (when all the nodes )
// Space Complexity - O(V+E) as minHeap takes up space E and array to store if node is included in mst or not is V so space complexity becomes O(E+V) and also for adjacency list O(E+V)
// https://stackoverflow.com/questions/20430740/time-complexity-of-prims-algorithm

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		vector<pair<pair<int, int>, int>> g;
		cin >> n >> m;
		int M = m;
		while (M--)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g.push_back({{u, v}, w});
		}
		cout << "Calling function " << endl;
		vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, g);
		cout << "Mininum Spanning Tree using Prim's algorithm is : " << endl;
		for (auto i : ans)
		{
			cout << i.first.first << " " << i.first.second << " " << i.second << endl;
		}
	}
	return 0;
}
/*
1
5 6
1 2 2
2 3 3
2 4 3
1 4 6
3 5 7
2 5 5
*/