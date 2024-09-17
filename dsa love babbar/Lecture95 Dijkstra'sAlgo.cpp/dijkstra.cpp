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

        // METHOD: 1 Using set
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
        return distance;

        // METHOD: 2 Using priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            pair<int, int> tpnd = pq.top();
            pq.pop();

            for (auto it : adj[tpnd.second])
            {
                int edge = it[1];
                int neighbour = it[0];

                if (tpnd.first + edge < dist[neighbour])
                {
                    dist[neighbour] = tpnd.first + edge;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        // return dist;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
