#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createAdj(vector<pair<int, int>>& edges, int n) {

    vector<int> ans[n + 1];
    int e = edges.size();

    for( pair<int, int> i : edges ) {
        int u = i.first;
        int v = i.second;

        ans[u].push_back(v);
    }

    vector<vector<int>> adj(n + 1);
    for( int i = 1; i <= n; i++ ) {
        for( int j : ans[i] ) {
            adj[i].push_back(j);
        }
    }

    return adj;
}

bool checkCycleDFS(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& dfsVisited, int node) {
    visited[node] = true;
    dfsVisited[node] = true;

    for( auto i : adj[node] ) {
        if( !visited[i] ) {
            bool cycleDetected = checkCycleDFS(adj, visited, dfsVisited, i);
            if( cycleDetected ) return true;
        } else if( dfsVisited[i] ) {
            return true;
        }
    }


    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector< pair < int, int >>& edges) {

    // create adjceny
    vector<vector<int>> adj = createAdj(edges, n);

    vector<bool> visited(n + 1);
    vector<bool> dfsVisited(n + 1);

    for( int i = 1; i <= n; i++ ) {
        if( !visited[i] ) {
            bool cycleDetected = checkCycleDFS(adj, visited, dfsVisited, i);
            if( cycleDetected ) return true;
        }
    }

    return false;
}

int main() {

    int node = 5;

    vector<pair<int, int>> edges = {
        {1, 2},
        {4, 1},
        {2, 4},
        {3, 4},
        {5, 2},
        {1, 3}
    };

    cout << "The Cycle is detected in the graph : " << detectCycleInDirectedGraph(node, edges);

    return 0;
}