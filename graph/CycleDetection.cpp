#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> createAdj(vector<vector<int>>& edges, int n, int e) {

    // maping edges
    vector<int> ans[n];
    for( int i = 0; i < e; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);

    for( int i = 0; i < n; i++ ) {
        for( int j : ans[i] ) {
            adj[i].push_back(j);
        }
    }
    return adj;
}

string solveBFS(vector<vector<int>> adj, int n) {


    // travesal bfs

    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while( !q.empty() ) {
        int frontNode = q.front();
        q.pop();

        for( int i : adj[frontNode] ) {
            if( visited[i] == 0 ) {
                q.push(i);
                visited[i] = 1;
            }
        }



    }

    return "No";

}

string solve(vector<vector<int>>& adj, int n, int e) {
    vector<int> visited(n);

    for( int i = 0; i < n; i++ ) {
        if( visited[i] == 0 ) {
            bool ans = solveBFS()
        }
    }
}


string cycleDetection(vector<vector<int>>& edges, int n, int e) {
    vector<vector<int>> adj = createAdj(edges, n, e);
    return solveBFS(adj, n);
}

int main() {

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4},
        {4, 5},
        {4, 6},
        {4, 6},
        {6, 7},
        {5, 7},
        {7, 8}
    };

    int n = 9;
    int e = edges.size();

    cout << "Cycle detected Yes or No : " << cycleDetection(edges, n, e);

    return 0;
}