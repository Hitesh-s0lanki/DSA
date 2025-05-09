#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void print(vector<int> distance) {
    for( int i : distance ) {
        cout << i << "\t";
    }
    cout << endl;
}

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int src) {


    vector<pair<int, int>> adj[n];
    for( int i = 0; i < times.size(); i++ ) {
        int u = times[i][0] - 1;
        int v = times[i][1] - 1;
        int w = times[i][2];

        adj[u].push_back(make_pair(v, w));
    }

    // due to 0 indexing 
    src--;

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push(make_pair(0, src));

    while( !pq.empty() ) {

        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for( pair<int, int> i : adj[node] ) {
            int neighbour = i.first;
            int neighbourWeight = i.second;
            if( distance[node] + neighbourWeight < distance[neighbour] ) {
                distance[neighbour] = distance[node] + neighbourWeight;
                pq.push(make_pair(distance[neighbour], neighbour));
            }
        }
    }

    int max = -1;

    for( int i : distance ) {
        if( i == INT_MAX ) return -1;
        if( i > max ) max = i;
    }

    return max;

}

int main() {

    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    cout << "The minimum time it takes for all the n nodes to receive the signal : " << networkDelayTime(times, 4, 2);


    return 0;
}