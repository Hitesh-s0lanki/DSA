#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
    unordered_map<int, list<int>> adj;

public:

    void addEdge(int u, int v, bool direction) {

        adj[u].push_back(v);

        if( direction == 0 ) {
            adj[v].push_back(u);
        }

    }

    void printAdjList() {
        for( auto i : adj ) {
            cout << i.first << " -> ";
            for( auto j : i.second ) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

};

int main() {

    Graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(0, 4, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);

    g.printAdjList();
    return 0;
}