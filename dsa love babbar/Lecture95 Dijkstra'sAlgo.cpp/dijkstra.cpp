/*
dijkstra is nothing but calculating distance of all nodes from a single source node as we have done in lecture 93, just the difference is the weight of eadges is not 1 hence we have to select node with minimum edges using set in this algo
Note - the dijkstra's algorithm doesn't works on the graph with negative edges - suppose we have two nodes 0 and 1 with edge -2 then dist[0] = 0 and dist[1] = -2 and at node 2 we will again see that dist[1] + adjList[1][0] = -4 < 0 and in this way it will go on infinitely updating more negative distance as smallest.
for detailed - https://youtu.be/V6H1qAeB-l4?feature=shared at 18:13

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// from the source vertex S.
	vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
	{
		// METHOD: 1  Using set
		vector<int> distance(V, 1e9);
		distance[S] = 0;
		set<pair<int, int>> st;
		st.insert({0, S});

		while (!st.empty())
		{
			int dis = st.begin()->first;
			int node = st.begin()->second;
			st.erase(st.begin());
			for (auto i : adj[node])
			{

				if (distance[i[0]] > dis + i[1])
				{
					distance[i[0]] = dis + i[1];
					auto record = st.find({distance[i[0]], i[0]}); // DOUBT: why we check for previous occurance of element in the set method while not in the priority queue method - https://chatgpt.com/share/e4df3eef-67db-473a-b340-141b0a2a209c (in short the distance which are greater are automatically ignored in this algorithm)
					if (record != st.end())
					{
						st.erase(*record);
					}
					st.insert({distance[i[0]], i[0]});
				}
			}
		}

		// METHOD: 2 Using priority queue
		priority_queue<pair<int, int>> pq;
		vector<int> dist(V, 1e9);

		dist[S] = 0;
		pq.push({0, S});

		while (!q.empty())
		{
			int dis = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			for (auto it : adj[node])
			{
				int edgeWeight = it[1];
				int adjNode = it[0];

				if (dis + edgeWeight < dist[adjNode])
				{
					dist[adjNode] = dis + edgeWeight;
					pq.push({adjNode, dis[adjNode]});
				}
			}
		}
		return distance;
	}
};

int main()
{

	return 0;
}