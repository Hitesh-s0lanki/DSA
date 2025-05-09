#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Compare {
public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first > b.first;
    }
};

bool isValid(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

int minTimeToReach(vector<vector<int>>& moveTime) {

    int row = moveTime.size();
    int col = moveTime[0].size();

    // distance vector with INT_MAX value all around
    vector<vector<int>> distance(row, vector<int>(col, INT_MAX));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;

    pq.push(make_pair(0, make_pair(0, 0)));
    distance[0][0] = 0;
    vector<vector<int>> moves = {
        {-1, 0}, // Up
        {1, 0}, // down
        {0, 1}, // right
        {0, -1} // left
    };

    int alternating = 1;

    while( !pq.empty() ) {
        int weight = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if( x == row - 1 && y == col - 1 ) return distance[x][y];

        for( int d = 0; d < moves.size(); d++ ) {
            int nrow = x + moves[d][0];
            int ncol = y + moves[d][1];

            if( isValid(nrow, ncol, row, col) ) {
                int arrive = weight + 1;
                int wait = moveTime[nrow][ncol] + 1;
                int nextTime = max(arrive, wait);

                if( nextTime < distance[nrow][ncol] ) {
                    distance[nrow][ncol] = nextTime;
                    pq.push(make_pair(nextTime, make_pair(nrow, ncol)));
                }

            }
        }
    }

    return -1;
}


int main() {

    // vector<vector<int>> moveTime = { {17,56}, {97,80} };
    // vector<vector<int>> moveTime = { {20,83,12}, {68,30,90}, {53,86,18} };
    // vector<vector<int>> moveTime = {
    //     {0, 4},
    //     {4, 4}
    // };
    vector<vector<int>> moveTime = {
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << minTimeToReach(moveTime);


    return 0;
}