#include <iostream>
#include <vector>
#include<cstdlib>
#include<climits>
#include<queue>
#include <tuple>

using namespace std;

bool isValid(vector<vector<int>>& moveTime, int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n && moveTime[row][col] != -1;
}

int solve(vector<vector<int>>& moveTime, int row, int col, int m, int n, int time) {
    if( !isValid(moveTime, row, col, m, n) ) return INT_MAX;

    int temp = moveTime[row][col];
    time = max(time, temp) + 1;

    if( row == m - 1 && col == n - 1 ) return time;

    moveTime[row][col] = -1;  // mark visited

    int upTime = solve(moveTime, row - 1, col, m, n, time);
    int downTime = solve(moveTime, row + 1, col, m, n, time);
    int leftTime = solve(moveTime, row, col - 1, m, n, time);
    int rightTime = solve(moveTime, row, col + 1, m, n, time);

    moveTime[row][col] = temp;

    return min(upTime, min(downTime, min(leftTime, rightTime)));
}

// int minTimeToReach(vector<vector<int>>& moveTime) {
//     int m = moveTime.size(), n = moveTime[0].size();

//     int ans = INT_MAX;

//     if( isValid(moveTime, 0, 1, m, n) ) {
//         vector<vector<int>> copy = moveTime;
//         ans = min(ans, solve(copy, 0, 1, m, n, 0));
//     }

//     if( isValid(moveTime, 1, 0, m, n) ) {
//         vector<vector<int>> copy = moveTime;
//         ans = min(ans, solve(copy, 1, 0, m, n, 0));
//     }

//     return ans;
// }

int minTimeToReach(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    typedef tuple<int, int, int> T;

    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0][0] = grid[0][0];
    pq.push(make_tuple(grid[0][0], 0, 0));

    int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

    while( !pq.empty() ) {
        T top = pq.top(); pq.pop();
        int currTime = get<0>(top);
        int x = get<1>(top);
        int y = get<2>(top);

        if( x == m - 1 && y == n - 1 ) return currTime;

        for( int d = 0; d < 4; ++d ) {
            int nx = x + dirs[d][0];
            int ny = y + dirs[d][1];

            if( nx >= 0 && ny >= 0 && nx < m && ny < n ) {
                int arrive = currTime + 1;
                int wait = grid[nx][ny];
                int nextTime = max(arrive, wait);

                if( nextTime < dist[nx][ny] ) {
                    dist[nx][ny] = nextTime;
                    pq.push(make_tuple(nextTime, nx, ny));
                }
            }
        }
    }

    return -1;
}

int main() {

    // vector<vector<int>> moveTime = { {17,56}, {97,80} };
    // vector<vector<int>> moveTime = { {20,83,12}, {68,30,90}, {53,86,18} };
    vector<vector<int>> moveTime = { {0,0,0}, {0,0,0} };
    // vector<vector<int>> moveTime = { {0,1}, {1, 2} };
    // vector<vector<int>> moveTime = { {15,58}, {67, 4} };
    int result = minTimeToReach(moveTime);

    cout << "Minimum time to reach the destination: " << result << endl;

    return 0;
}