#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges, int n, int e) {

    vector<int> adj[n];
    for( int i = 0; i < e; i++ ) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(n);
    for( int i = 0; i < n; i++ ) {
        for( auto j : adj[i] ) {
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
        ans.push_back(frontNode);
        q.pop();

        for( int i : adj[frontNode] ) {
            indegree[i]--;
            if( indegree[i] == 0 ) {
                q.push(i);
            }
        }
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