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

void dfs(int node, int parent, int timer, vector<int>& disc, vector<int>& low, vector<vector<int>>& result, vector<bool>& visited, vector<vector<int>> adj) {
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for( int neighbour : adj[node] ) {
        if( neighbour == parent ) continue;

        if( !visited[neighbour] ) {
            dfs(neighbour, node, timer, disc, low, result, visited, adj);
            low[node] = min(low[node], low[neighbour]);

            // check if the brigde is there or not
            if( low[neighbour] > disc[node] ) {
                result.push_back({ node, neighbour });
            }
        } else {
            // backage condition
            low[neighbour] = min(low[node], disc[neighbour]);
        }
    }


}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int n, int e) {

    // create adjacency list
    vector<vector<int>> adj(n);
    for( int i = 0; i < e; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n);

    int parent = -1;

    vector<vector<int>> result;

    for( int i = 0; i < n; i++ ) {
        if( !visited[i] ) {
            dfs(i, parent, timer, disc, low, result, visited, adj);
        }
    }

    return result;
}

int main() {

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {1, 3},
        {3, 4}
    };

    print(findBridges(edges, 5, 4));

    return 0;
}