#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void print(vector<int> ans) {
    for( auto i : ans ) {
        cout << i << "\t";
    }
    cout << endl;
}

void print(vector<pair<pair<int, int>, int>> edges, int n) {
    vector<pair<int, int>> adj[n + 1];
    for( int i = 0; i < edges.size(); i++ ) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }


    // print the answer 
    for( int i = 1; i <= n; i++ ) {
        cout << i << " -> ";
        for( auto j : adj[i] ) {
            cout << "{" << j.first << ", " << j.second << "}, ";
        }
        cout << endl;
    }
}

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int e, vector<pair<pair<int, int>, int>>& edges) {

    // create a adjaceny list
    vector<pair<int, int>> adj[n + 1];
    for( int i = 0; i < e; i++ ) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> parent(n + 1, -1);
    vector<int> distance(n + 1, INT_MAX);
    vector<bool> inMST(n + 1, false);

    distance[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push(make_pair(0, 1));

    while( !pq.empty() ) {
        int node = pq.top().second;
        pq.pop();

        if( inMST[node] ) continue;
        inMST[node] = true;

        // visit the neighbour child
        for( pair<int, int> i : adj[node] ) {
            int neigbhour = i.first;
            int weight = i.second;
            if( !inMST[neigbhour] && weight < distance[neigbhour] ) {
                distance[neigbhour] = weight;
                pq.push(make_pair(weight, neigbhour));
                parent[neigbhour] = node;
            }
        }

    }

    vector<pair<pair<int, int>, int>> ans;

    for( int i = 2; i <= n; i++ ) {
        ans.push_back(make_pair(make_pair(parent[i], i), distance[i]));
    }

    return ans;
}

int main() {

    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 5},
        {{1, 3}, 8},
        {{2, 3}, 10},
        {{2, 4}, 15},
        {{4, 3}, 20}
    };

    print(calculatePrimsMST(4, edges.size(), edges), 4);

    return 0;
}