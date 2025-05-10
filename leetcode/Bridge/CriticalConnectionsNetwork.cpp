#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        cout << "{";
        for( auto j : i ) {
            cout << j << ", ";
        }
        cout << "}, ";
    }
    cout << endl;
}

void dfs(int node, int parent, int timer, vector<int>& disc, vector<int>& low, vector<vector<int>>& result, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[node] = true;

    low[node] = disc[node] = timer++;

    for( int neighbour : adj[node] ) {

        if( neighbour == parent ) continue;

        if( !visited[neighbour] ) {
            dfs(neighbour, node, timer, disc, low, result, visited, adj);
            low[node] = min(low[node], low[neighbour]);

            if( low[neighbour] > disc[node] ) {
                result.push_back({ node, neighbour });
            }

        } else {
            // back log age
            low[node] = min(low[node], disc[neighbour]);
        }

    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

    // prepare adjacency list
    vector<vector<int>> adj(n);
    for( int i = 0; i < connections.size(); i++ ) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n);

    int parent = -1;
    int timer = 0;

    vector<vector<int>> result;

    for( int i = 0; i < n; i++ ) {
        if( !visited[i] ) {
            dfs(i, parent, timer, disc, low, result, visited, adj);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}
    };

    print(criticalConnections(4, connections));

    return 0;
}