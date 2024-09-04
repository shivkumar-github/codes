// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
class Solution {
  public:
     public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src){
        // built a tree
        vector<vector<int>> adjList(N);
        
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }    
        
        // so rather than finding distance of each node we should optimise the code so that the nodes in the path of source node and dest will also get their distance calculated reducing the time complexity
        // to store the values of the nodes in path we will have to keep an array that will track the distances for all nodes
        // we will initialise with a large value as n and m < 10 ^4 we will take it as 1e9
        vector<int> dst(N, 1e9);
        dst[src] = 0;
        // after that we will do bfs 
        // DOUBT: WHY NOT DFS

        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adjList[node]){
                if(dst[node] + 1 < dst[it]){
                    // if previously stored distance is greater than the curr distance
                    dst[it] = dst[node] + 1;
                    // if distanc is smaller that means it it the shorter path to reach the it node hence also might be shorter path to reach further nodes hence push it in q to perform bfs on it
                    q.push(it);
                }
            }
        }
        for(int i = 0;i<N;i++){ // if distance is still 1e9 that means we can not reach the node hence set it to -1
            if(dst[i] == 1e9)
                dst[i] = -1;
        }
        return dst;
    // space complexity DOUBT: What will be the space complexity of adjList and adjMat O(N^2) or O(N*M)
    } // tc = O(N+M) DOUBT:
};

