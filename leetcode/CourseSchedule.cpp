#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int n, vector<vector<int>>& edges) {

    vector<int> adj[n];
    for( int i = 0; i < edges.size(); i++ ) {
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

    int cnt = 0;
    while( !q.empty() ) {
        int frontNode = q.front();
        q.pop();
        cnt++;

        for( int i : adj[frontNode] ) {
            indegree[i]--;
            if( indegree[i] == 0 ) {
                q.push(i);
            }
        }
    }

    return cnt == n;
}

int main() {

    vector<vector<int>> edges = {
        {1, 0}
        //  {0, 1}
    };
    int vertex = 2;

    cout << "You can finish all courses : " << canFinish(vertex, edges);

    return 0;
}