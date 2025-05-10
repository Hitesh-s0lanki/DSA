// important *********

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

void makeSet(int n, vector<int>& parent, vector<int>& rank) {
    for( int i = 0; i < n; i++ ) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int>& parent) {
    if( parent[node] == node ) return node;

    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if( rank[u] < rank[v] ) {
        parent[v] = u;
    } else if( rank[u] > rank[v] ) {
        parent[u] = v;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}


int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(n, parent, rank);

    int miniWeight = 0;

    for( auto i : edges ) {

        int u = findParent(i[0], parent);
        int v = findParent(i[1], parent);
        int weight = i[2];

        if( u != v ) {
            miniWeight += weight;
            unionSet(u, v, parent, rank);
        }

    }

    return miniWeight;
}

int main() {

    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 3, 5},
        {1, 2, 1},
        {2, 3, 8}
    };

    cout << "the minimum possible total edge weight : " << minimumSpanningTree(edges, 4);

    return 0;
}