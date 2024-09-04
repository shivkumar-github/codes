/*
https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
https://www.geeksforgeeks.org/problems/topological-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
Kahn’s Algorithm works by repeatedly finding vertices with no incoming edges, removing them from the graph, and updating the incoming edges of the remaining vertices. This process continues until all vertices have been ordered.
Algorithm:
Add all nodes with in-degree 0 to a queue.
	While the queue is not empty:
	Remove a node from the queue.
	For each outgoing edge from the removed node, decrement the in-degree of the destination node by 1.
	If the in-degree of a destination node becomes 0, add it to the queue.
	If the queue is empty and there are still nodes in the graph, the graph contains a cycle and cannot be topologically sorted.
	The nodes in the queue represent the topological ordering of the graph.

Basically we add the nodes with 0 incoming edges to the topological sort and then remove those edges from the graph to proceed further nodes
i.e. when indegree becomes 0 for a node according to the algorithm, this mean that all the parent nodes of the current node(with 0 indegree) have been now added to the sort hence we can now add the node itself.
Indegree of a node is the number of incoming edges to the node
*/

#include <bits/stdc++.h>
using namespace std;

// we are given an adjacency matrix and from that we have to prepare the topological sort
vector<int> topoSortUsingKahns(vector<vector<int>> adjList, int V)
{
	vector<int> indegree(V, 0);

	// calculating indegrees
	for (auto i : adjList)
	{
		for (int j : i)
		{
			indegree[j]++;
		}
	}

	// q to perform bfs
	queue<int> q;
	// pushing the nodes which have 0 indegree
	for (int i = 0; i < V; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int> ans;
	while (!q.empty())
	{
		int crNode = q.front();
		q.pop();
		ans.push_back(crNode);

		for (int child : adjList[crNode])
		{
			// 1 parent of the node is added to sort hence decrease the indegree of all it's child nodes
			indegree[child]--;

			// if indgegree becomes 0 that means all the parent nodes for this node are added to sort hence now this can be added to sort
			if (indegree[child] == 0)
				q.push(child);
		}
	}

	if (ans.size() != V)// if graph contains the cycle then the sort will contain less than V elments as all nodes will not be pushed in q 
	{
		cout << "Cyclic Graph!" << endl;
		return {};
	}
	return ans;
}
/*
Complexity Analysis :-
	Time Complexity - O(V+E)
	Space Complexity - O(V)
*/

int main()
{
	return 0;
}