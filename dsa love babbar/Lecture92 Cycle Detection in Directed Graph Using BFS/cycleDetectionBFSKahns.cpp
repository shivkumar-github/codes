// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // maintain count of nodes included in topo sort
        int cnt = 0;
        
        // initialise indegree(number of incoming edges to that node)
        vector<int> indegree(V, 0);
        for(int i = 0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0;i<V;i++){ // for disconnected graph
            if(indegree[i] == 0)
                q.push(i);
        }
        
        // perform bfs and add the node to bfs when indegree becomes 0 (indirectly removing the edges)
        while(!q.empty()){
            int crnd = q.front();
            q.pop();
            cnt++; // increase cnt for number of nodes in topo sort
            for(auto it : adj[crnd]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        // if cnt == V then graph doesn't contain cycle else 
        return cnt != V;
    }
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