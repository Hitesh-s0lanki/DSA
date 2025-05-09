#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createAdj(int n, int e, vector<vector<int>>& edges) {

    vector<int> ans[n];

    for( int i = 0; i < e; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adjs(n);

    for( int i = 0; i < n; i++ ) {
        for( int j : ans[i] ) {
            adjs[i].push_back(j);
        }
    }

    return adjs;
}

void dfs(int node, vector<vector<int>> adj, vector<int>& visited, vector<int>& ans) {
    visited[node] = 1;

    ans.push_back(node);

    for( int i : adj[node] ) {
        if( !visited[i] ) {
            dfs(i, adj, visited, ans);
            visited[i] = 1;
        }
    }
}

vector<vector<int>> depthFirstSearch(int n, int e, vector<vector<int>>& edges) {
    vector<vector<int>> adjs = createAdj(n, e, edges);


    vector<vector<int>> ans;
    vector<int> visited(n);

    for( int i = 0; i < n; i++ ) {
        vector<int> temp;
        if( visited[i] == 0 ) {
            dfs(i, adjs, visited, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}

void print(vector<vector<int>> ans) {
    for( int i = 0; i < ans.size(); i++ ) {
        for( int j : ans[i] ) {
            cout << j << ", ";
        }
        cout << endl;
    }
}

int main() {

    int n = 5;
    int e = 4;

    vector<vector<int>> edges = {
        {0, 2},
        {0, 1},
        {1, 2},
        {3, 4}
    };

    print(depthFirstSearch(n, e, edges));

    return 0;
}