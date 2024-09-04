// practicing dfs and bfs traversal
// assuming that the edges matrix is given for the tree
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adjList, vector<bool>& visited, vector<int>& ans, int source){
	queue<int> q;
	q.push(source);
	visited[source] = true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto i : adjList[node]){
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

vector<int> bfsTraversal(vector<vector<int>> edges, int n, int source)
{
	// prepare adjList at first
	vector<vector<int>> adjList(n);
	for(auto i : edges){
		adjList[i[0]].push_back(i[1]);
		adjList[i[1]].push_back(i[0]);
	}

	// considering the graph is disconnected and we are supposed to print the nodes that are not connected to the source node
	// as we are supposed to traverse from a source node first we have to do bfsRec on the source node and then on the other remaining nodes
	vector<int> ans; // to store the traversal
	vector<bool> visited(n, false); // to track if the node is previously visited or not
	bfs(adjList, visited, ans);
	// do for the remaining nodes
	for (int i = 0; i < n;i++){
		if(!visited[i]){
			bfs(adjList, visited, ans, i);
		}
	}
	return ans;
}




int main()
{
	return 0;
}