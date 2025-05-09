#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> createAdj(vector<vector<int>>& edges, int n, int e) {

    vector<int> ans[n];
    for( int i = 0; i < e; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
    }

    vector<vector<int>> adj(n);
    for( int i = 0; i < n; i++ ) {
        for( int j : ans[i] ) {
            adj[i].push_back(j);
        }
    }

    return adj;
}

void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s, int node) {
    visited[node] = true;

    for( auto i : adj[node] ) {
        if( !visited[i] ) {
            dfs(adj, visited, s, i);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {

    vector<vector<int>> adj = createAdj(edges, v, e);

    // use of data structure for solution
    vector<bool> visited(v);
    stack<int> s;

    for( int i = 0; i < v; i++ ) {
        if( !visited[i] ) {
            dfs(adj, visited, s, i);
        }
    }

    // putting the ans back
    vector<int> ans(v);
    int i = 0;
    while( !s.empty() ) {
        int top = s.top();
        s.pop();

        ans[i] = top;
        i++;
    }

    return ans;
}

void print(vector<int> ans) {
    for( int i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {

    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {3, 2}
    };

    int vertex = 4;

    print(topologicalSort(edges, vertex, edges.size()));

    return 0;
}