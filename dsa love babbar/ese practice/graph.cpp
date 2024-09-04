/*

*/

#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v){
        adjList[u].push_back(v);
} 
// TODO: why directed?

void printAdj(vector<vector<int>> adjList){
        for (int i = 0; i < adjList.size();i++)
        {
                cout<< i << " -> ";
                for (int j = 0; j < adjList[i].size();j++)
                {
                        cout<< adjList[i][j] << " ";
                }
                cout << endl;
        }
        
}

int main(){
        int vertices = 5;
        vector<vector<int>> adjList(5);
        addEdge(adjList, 0, 1);
        addEdge(adjList, 0, 2);
        addEdge(adjList, 1, 3);
        addEdge(adjList, 2, 4);
        addEdge(adjList, 3, 4);
        addEdge(adjList, 1, 2);
        printAdj(adjList);
        return 0;
}