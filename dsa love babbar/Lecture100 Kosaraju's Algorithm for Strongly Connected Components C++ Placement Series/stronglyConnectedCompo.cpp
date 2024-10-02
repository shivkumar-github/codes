/*

*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int crnd, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &vis, stack<int> &st)
{
	vis[crnd] = true;
	for (auto nbr : adjList[crnd])
	{
		if (!vis[nbr])
		{
			dfs(nbr, adjList, vis, st);
		}
	}
	st.push(crnd);
}

void revDfs(int crnd, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList)
{
	vis[crnd] = true;

	for (int nbr : adjList[crnd])
	{
		if (!vis[nbr])
		{
			revDfs(nbr, vis, adjList);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adjList;
	for (auto it : edges)
	{
		adjList[it[0]].push_back(it[1]);
	}

	// topo sort - why Topo sort (so that for every u -> v in graph dfs of u should be called first so as to check if there exist any path from u to v in transpose graph)
	stack<int> st;
	unordered_map<int, bool> vis;
	for (int i = 0; i < v; i++)
	{
		if (!vis[i])
		{
			dfs(i, adjList, vis, st);
		}
	}

	// create a transpose graph (why to take tranpose - so that if there exits a path from u to v, we have to check if there is also a path from v to u)
	unordered_map<int, list<int>> transpose;
	for (int i = 0; i < v; i++)
	{
		vis[i] = false;
		for (auto nbr : adjList[i])
		{
			transpose[nbr].push_back(i);
		}
	}

	// dfs call using above order
	int cnt = 0;
	while (!st.empty())
	{
		int crnd = st.top();
		st.pop();
		if (!vis[crnd])
		{
			cnt++;
			revDfs(crnd, vis, transpose);
		}
	}
	return cnt;
}

int main()
{
	int V, E;
	cin >> V >> E;
	vector<vector<int>> edges;
	while(E--){
		vector<int> t(2);
		cin >> t[0] >> t[1];
		edges.push_back(t);
	}
	cout << stronglyConnectedComponents(V, edges) << endl;
	return 0;
}