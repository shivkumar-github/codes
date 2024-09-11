#include<vector>
#include<queue>
#include<iostream>
using namespace std;

// preparing adjcency list for a directed graph
void prepareAdjList(vector<vector<int>>& adjList, vector<vector<int>>& edges){
    for(int i = 0;i<edges.size();i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
}

// bfs traversal
void bfs(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& ans, int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i : adjList[node]){
            if(!visited[adjList[node][i]]){
                q.push(adjList[node][i]);
                visited[adjList[node][i]] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>>& edges, int root=0){
    vector<vector<int>> adjList(n);
    prepareAdjList(adjList, edges);
    vector<bool> visited(n, false);
    vector<int> ans;
    bfs(adjList, visited, ans, root); // if given a root/source node we will have to perform
    for(int i = 0;i<n;i++){ // fot the disconnected graph
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}
// time Complexity - O(E+V) - (the loop insider the main function will execute for V times and the for loop insider the utility function iterating over the adjacency list will executed for 2E times in total for undirected graph and E times for directed graph)
// space complexity - O(E+V) - space for the adjacency list

int  main(){

    vector<vector<int>> adj = {{0,1},{0,2},{0,3},{1,4},{1,7},{2,5},{3,6}};
    int n =8 ;
    vector<int> ans = bfsTraversal(n, adj);
    for(int i = 0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}