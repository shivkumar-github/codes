// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Utility function to perform dfs traversal
    bool dfs(int crnd, vector<int> adj[], vector<bool>&visited, vector<bool>& isInDFS){ // we have to pass the dfs vector by reference because if we directly pass by value, for each call a new copy of isInDFS will be created which will take O(V) time which can lead to TLE, or you can also use a normal pointer to pass the array
        visited[crnd] = true;
        isInDFS[crnd] = true;
        for(auto it:adj[crnd]){// we can not apply same condition to check cycle in directed graph as undirected graph because it will give wrong answer (to understand see the image)
            if(!visited[it]){
                bool ans = dfs(it, adj, visited, isInDFS);
                if(ans) return true;
            }
            else if(isInDFS[it]){ // && visited[it]
                return true;
            }
        }
        isInDFS[crnd] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // we need to keep track of the nodes which are present in current dfs path and if that nodes is reached again then the graph contain the cycle
        vector<bool> isInDFS(V, false);
        vector<bool> visited(V, false);
        for(int it = 0;it<V;it++){
            if(!visited[it]){
                bool ans = dfs(it, adj, visited, isInDFS);
                if(ans) return true;
            }
        }
        return false;
    } // time Complexity - O(E+V) 
    // space complexity - O(V)
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends