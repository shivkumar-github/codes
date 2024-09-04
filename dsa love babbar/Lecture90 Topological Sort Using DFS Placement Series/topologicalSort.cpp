/*Theory on gfg - https://www.geeksforgeeks.org/topological-sorting/ 
Problme link - https://www.geeksforgeeks.org/problems/topological-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

topological sort is the sequence where the node directing to a node(directly or indirectly) comes before that node in the topological sort
sort where for each u -> v u comes before v
Hence it only applicable for only directed graphs 
also if it is cyclic then we can not clearly define which node is the parent node hence we can not decide order between them 
due to these reasons topological sort is only applicable on directed alicyclic graph(DAG)

*/
#include<bits/stdc++.h>
using namespace std;
// The main difference between dfs and topo sort is DFS adds the current node to the result before exploring its adjacent nodes, whereas topological sort adds the node only after all its adjacent nodes have been processed.
// code from gfg (Implementation of topological sort using dfs)
void topologicalSortUtil(int cr, vector<vector<int>> & adjList, vector<bool> visited, stack<int> st){
	visited[cr] = true; // mark current node as visited
	
	// first recure for all adjacent nodes
	for(int i : adjList[cr])
		if(!visited[i])
			topologicalSortUtil(i, adjList, visited, st);


	// push current vertex to stack which is storing the result
	st.push(cr);// DOUBT: if we need the parent node at first then why we are not taking a fifo data structure and adding parent first and then processing child nodes (find the reason by doing dry run)
}
void topologicalSort(vector<vector<int>> &adjList, int V) // V = number of nodes
{
	stack<int> st; // why stack - as we are first processing neighbours and then the main , but in the answer our main node should appear first hence we need a data structur following LIFO 
	vector<bool> visited(V, false);

	// topological sort starting from all the vertices one by one
	for (int i = 0; i < V;i++)
		if(!visited[i])
			topologicalSortUtil(i, adjList, visited, st);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
// Time complexity - O(V+E)
// Space Complexity - O(V) extra space for stack