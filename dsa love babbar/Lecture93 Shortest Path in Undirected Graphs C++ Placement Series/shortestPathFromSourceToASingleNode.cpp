// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297
// In this question we have to find the shortest path from the source node to given single node
#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, vector<int>> adjList;
	
	for(auto it : edges){
		adjList[it.first].push_back(it.second);
		adjList[it.second].push_back(it.first);
	}
	// to track the whole path we have to creat a vector parent which will keep the track of parent of that node in shortest path 
	// after iterating till the destination node we will set it's parent and then we will backttrack using the parent vector till source and from that we will get a reversed path for that vector
	queue<int> q;
	unordered_map<int, int> parent;
	unordered_map<int, bool> visited; // to keep track of node which is previously visited (just like we compared distance in all nodes problem)

	// BFS traversal
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it : adjList[node]){
			if(!visited[it]){
				visited[it] = true;
				parent[it] = node;
				q.push(it);
			}
		}
	}


	// backtrack to source node to prepare shortest path
	vector<int> ans;
	int crNd = t;
	while(crNd != s){
		ans.push_back(crNd);
		crNd = parent[crNd];
	}
	ans.push_back(s);
	// path will be in reversed order
	reverse(ans.begin(), ans.end());
	return ans;
} 

// Time Complexity - O(N+E) DOUBT: how + E for both space and time complexity
// Space Complexity - O(N+E) for ans and parent and q 
// DOUBT: if we consider space complexity for adjList then for each edge present there will be two elements inserted in the adjlist hence shouldn't it must be O(E)