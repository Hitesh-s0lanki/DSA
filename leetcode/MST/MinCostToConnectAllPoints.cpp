#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

class Compare {
public:
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

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
        parent[u] = v;
    } else if( rank[u] > rank[v] ) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;

    for( int u = 0; u < n - 1; u++ ) {
        for( int v = u + 1; v < n; v++ ) {
            pq.push(make_pair(make_pair(u, v), manhattan_distance(points[u][0], points[u][1], points[v][0], points[v][1])));
        }
    }

    // Kruskar algo
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(n, parent, rank);

    int miniWeight = 0;

    while( !pq.empty() ) {

        pair<pair<int, int>, int> frontNode = pq.top();

        int u = findParent(frontNode.first.first, parent);
        int v = findParent(frontNode.first.second, parent);
        int weight = frontNode.second;

        pq.pop();

        if( u != v ) {
            miniWeight += weight;
            unionSet(u, v, parent, rank);
        }
    }

    return miniWeight;
}

int usingPrims(vector<vector<int>>& points) {
    int n = points.size();

    vector<int> distance(n, INT_MAX);
    vector<bool> isMST(n);

    distance[0] = 0;
    int miniWeight = 0;

    for( int i = 0; i < n; i++ ) {

        // get the cheapest node
        int u = -1;
        for( int j = 0; j < n; j++ ) {
            if( !isMST[j] && (u == -1 || distance[j] < distance[u]) ) {
                u = j;
            }
        }

        isMST[u] = true;
        miniWeight += distance[u];



        for( int v = 0; v < n; ++v ) {
            if( !isMST[v] ) {
                int d = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                if( d < distance[v] ) {
                    distance[v] = d;
                }
            }
        }

    }


    return miniWeight;
}


int main() {

    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << "The minimum cost to make all points connected : " << usingPrims(points);

    return 0;
}