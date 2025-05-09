#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}

vector<int> findOrder(int n, vector<vector<int>>& edges) {

    vector<int> adj[n];
    for( int i = 0; i < edges.size(); i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[v].push_back(u);
    }

    vector<int> indegree(n);
    for( int i = 0; i < n; i++ ) {
        for( int j : adj[i] ) {
            indegree[j]++;
        }
    }

    queue<int> q;
    for( int i = 0; i < n; i++ ) {
        if( indegree[i] == 0 ) {
            q.push(i);
        }
    }

    vector<int> ans;
    while( !q.empty() ) {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for( int i : adj[frontNode] ) {
            indegree[i]--;
            if( indegree[i] == 0 ) {
                q.push(i);
            }
        }
    }

    if( ans.size() != n ) {
        return {};
    }

    return ans;
}

int main() {

    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };
    int vertex = 4;

    print(findOrder(vertex, edges));

    return 0;
}