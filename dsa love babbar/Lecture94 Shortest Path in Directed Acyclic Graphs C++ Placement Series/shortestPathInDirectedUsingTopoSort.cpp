/*

*/

#include <bits/stdc++.h>
using namespace std;

// Approach contains mainly two steps
// 1. find the topo logical sort order
// 2. update the distance array according to the topological sort

class Solution
{
public:
	// utility function which for topo sort
	void dfsUtil(int crNd, stack<int> &st, vector<bool> &visited, unordered_map<int, list<pair<int, int>>> adjList)
	{
		visited[crNd] = true;
		for (auto child : adjList[crNd])
		{
			if (!visited[child.first])
			{
				dfsUtil(child.first, st, visited, adjList);
			}
		}
		st.push(crNd);
	}

	// main function to calculate distances
	vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
	{
		int src = 1; // given in problem but we are solving problem for unknown source node
		unordered_map<int, list<pair<int, int>>> adjList;
		for (auto i : edges)
		{
			adjList[i[0]].push_back({i[1], i[2]});
		}

		stack<int> st;
		vector<bool> visited(N, false);
		for (int i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				dfsUtil(i, st, visited, adjList);
			}
		}
		// here the topo sort is calculated in the stack, now we will continue with topo sort

		vector<int> distance(N, INT_MAX); // initialise with INT_MAX
		distance[src] = 0;
		// for whole topo sort
		while (!st.empty())
		{
			int top = st.top();
			st.pop();
			if (distance[top] == INT_MAX)
				continue; // the node is not reachable from the source node
			for (auto i : adjList[top])
			{
				if (distance[top] + i.second < distance[i.first]) // if distance through top node is lesser than previously stored distance then update the distance
				{
					distance[i.first] = distance[top] + i.second;
				}
			}
		}

		// modify the answer according to the requirements
		for (int i = 0; i < distance.size(); i++)
		{
			if (distance[i] == INT_MAX)
			{
				distance[i] = -1; // according to required answer in gfg
			}
		}

		return distance;
	}
};

int main()
{
	Solution s;
	int M, N;
	// change the source node in the function
	vector<vector<int>> edges;
	cin >> N >> M;
	int it = M;
	while(it--){
		int stNd, endNd, dist;
		cin >> stNd >> endNd >> dist;
		edges.push_back({stNd, endNd, dist});
	}
	vector<int> distance = s.shortestPath(N, M, edges);
	for(int i : distance) // we are returning -1 for the case where distance doesn't exist(on gfg no edges weight is negative but babbar has given negative weights)
		cout << i << " ";
	cout << endl;
	return 0;
}
/*

6 9 
0 1 5
0 2 3 
1 2 2
1 3 6
2 3 7
2 4 4 
2 5 2
3 4 -1
4 5 -2
*/