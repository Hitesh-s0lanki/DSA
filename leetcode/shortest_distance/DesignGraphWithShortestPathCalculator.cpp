#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

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

    int shortestPath(int src, int dist) {

        vector<int> distance(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        distance[src] = 0;
        pq.push(make_pair(0, src));

        while( !pq.empty() ) {
            pair<int, int> frontNode = pq.top();
            pq.pop();

            int d = frontNode.first;
            int node = frontNode.second;

            // Skip if a shorter path has already been found love babber valu hai Ooo
            if( d > distance[node] )
                continue;

            // If found the target node then return the cost
            if( node == dist )
                return d;

            for( vector<int> i : adj[node] ) {
                int neighbour = i[0];
                int neighbourWeight = i[1];
                if( distance[node] + neighbourWeight < distance[neighbour] ) {
                    distance[neighbour] = distance[node] + neighbourWeight;
                    pq.push(make_pair(distance[neighbour], neighbour));
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