#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int e, int s, int t) {

    vector<int> adj[n + 1];
    for( int i = 0; i < e; i++ ) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfs travesal
    queue<int> q;
    vector<int> parent(n + 1);
    vector<bool> visited(n + 1);

    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while( !q.empty() ) {
        int frontNode = q.front();
        q.pop();

        for( auto i : adj[frontNode] ) {
            if( !visited[i] ) {
                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
            }
        }
    }

    vector<int> ans;
    int currentNode = t;

    while( currentNode != -1 ) {
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {

    vector<pair<int, int>> edges = {
        {1, 2}
        // {1, 3},
        // {1, 4},
        // {2, 5},
        // {5, 8},
        // {3, 8},
        // {4, 6},
        // {6, 7},
        // {7, 8}
    };

    int n = 2;
    int e = edges.size();
    int s = 1;
    int t = 2;

    print(shortestPath(edges, n, e, s, t));

    return 0;
}