#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Graph {
    vector<vector<vector<int>>> adj;
    int n;

public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->adj.resize(n);

        int e = edges.size();
        for( int i = 0; i < e; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            this->adj[u].push_back({ v, w });
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        this->adj[u].push_back({ v, w });
    }

    void dfs(stack<int>& s, vector<bool>& visited, int node) {
        visited[node] = true;

        for( vector<int> i : adj[node] ) {
            int neighbour = i[0];
            if( !visited[neighbour] ) {
                dfs(s, visited, neighbour);
            }
        }

        s.push(node);
    }

    stack<int> topologicalSort() {
        vector<bool> visited(n);
        stack<int> s;

        for( int i = 0; i < n; i++ ) {
            if( !visited[i] ) {
                dfs(s, visited, i);
            }
        }

        return s;
    }

    int shortestPath(int src, int dist) {

        // creating distance array
        vector<int> distance;
        for( int i = 0; i < n; i++ ) {
            distance.push_back(INT_MAX);
        }

        distance[src] = 0;

        stack<int> s = topologicalSort();

        while( !s.empty() ) {
            int top = s.top();
            s.pop();

            if( distance[top] != INT_MAX ) {
                for( vector<int> i : adj[top] ) {
                    int neighbour = i[0];
                    int weight = i[1];
                    if( distance[top] + weight < distance[neighbour] ) {
                        distance[neighbour] = distance[top] + weight;
                    }
                }
            }
        }

        return distance[dist] == INT_MAX ? -1 : distance[dist];
    }

    void print() {
        for( int i = 0; i < n; i++ ) {
            cout << i << " -> ";
            for( vector<int> j : adj[i] ) {
                cout << "{" << j[0] << ", " << j[1] << "}, ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {

    vector<vector<int>> edges = { {0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3} };

    Graph G(4, edges);


    G.print();

    cout << "The Shortest part between 3 and 2 is :" << G.shortestPath(3, 2) << endl;

    cout << "The Shortest part between 0 and 3 is :" << G.shortestPath(0, 3) << endl;

    G.addEdge({ 1, 3, 4 });

    cout << "The Shortest part between 0 and 3 is :" << G.shortestPath(0, 3) << endl;

    G.print();

    return 0;
}