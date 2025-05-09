#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};

vector<int> dijkstra(vector<vector<int>>& edges, int n, int e, int source) {
    // prepare adjacency list 
    vector<pair<int, int>> adj[n];

    for( int i = 0; i < e; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    //creation of distance array with infinite value initially
    vector<int> distance(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    distance[source] = 0;
    pq.push(make_pair(0, source));

    while( !pq.empty() ) {
        pair<int, int> frontNode = pq.top();

        int weight = frontNode.first;
        int node = frontNode.second;

        pq.pop();

        for( pair<int, int> neighbour : adj[node] ) {
            if( distance[node] + neighbour.second < distance[neighbour.first] ) {
                distance[neighbour.first] = distance[node] + neighbour.second;
                pq.push(make_pair(neighbour.second, neighbour.first));
            }
        }

    }

    return distance;
}

void print(vector<int> ans) {
    for( int i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {

    vector<vector<int>> edges = {
        {0, 1, 7},
        {0, 2, 1},
        {0, 3, 2},
        {1, 2, 3},
        {1, 3, 5},
        {1, 4, 1},
        {3, 4, 7}
    };

    print(dijkstra(edges, 5, edges.size(), 0));

    return 0;
}