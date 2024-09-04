/*
creating a graph using unordered map i.e. adjacency list
*/

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// using template class to generalise the class for all types of datas
template <typename T>
class graph
{
public:
        unordered_map<T, list<T>> adjList;

        void adjEdges(T u, T v, bool direction)
        {
                // here we will consider direction = 1 -> directed list
                // and direction = 0 -> undirected
                adjList[u].push_back(v);
                if (!direction)
                {
                        adjList[v].push_back(u);
                }
        }

        void Printing()
        {
                for (auto i : adjList)
                {
                        cout << i.first << "-> ";
                        for (auto j : i.second) // i.second is just like an array // auto i confusion hua tha
                        {
                                cout << j << " ";
                        }
                        cout << endl;
                }
        }
};

int main()
{
        int edges;
        cout << "Enter number of edges : " << endl;
        cin >> edges;
        graph<int> g;

        for (int i = 0; i < edges; i++)
        {
                int u, v;
                cin >> u >> v;
                cout << "Enter data for edge " << i + 1 << endl;
                g.adjEdges(u, v, 0);
        }

        g.Printing();

        return 0;
}