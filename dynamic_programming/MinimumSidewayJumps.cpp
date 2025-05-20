#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<int>& ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

int recursion(vector<int>& obstacles, int index, int lane) {

    if( index == obstacles.size() - 1 )
        return 0;

    int ans = INT_MAX;

    // if no obstracle in the same lane
    if( obstacles[index + 1] != lane ) {
        ans = recursion(obstacles, index + 1, lane);
    } else {
        // changing the lane
        for( int i = 1; i <= 3; i++ ) {
            if( i != lane && obstacles[index] != i ) {
                int val = recursion(obstacles, index, i);
                if( val != INT_MAX )
                    ans = min(ans, val + 1);
            }
        }
    }

    return ans;
}

int memorization(vector<int>& obstacles, int index, int lane,
    vector<vector<int>>& dp) {

    if( index == obstacles.size() - 1 )
        return dp[lane][index] = 0;

    if( dp[lane][index] != -1 )
        return dp[lane][index];

    int ans = INT_MAX;

    // if no obstracle in the same lane
    if( obstacles[index + 1] != lane ) {
        ans = recursion(obstacles, index + 1, lane);
    } else {
        // changing the lane
        for( int i = 1; i <= 3; i++ ) {
            if( i != lane && obstacles[index] != i ) {
                int val = recursion(obstacles, index, i);
                if( val != INT_MAX )
                    ans = min(ans, val + 1);
            }
        }
    }

    return dp[lane][index] = ans;
}
int tabulation(vector<int>& obstacles) {
    int n = obstacles.size() - 1;

    vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for( int pos = n - 1; pos >= 0; pos-- ) {
        for( int lane = 1; lane <= 3; lane++ ) {
            if( obstacles[pos + 1] != lane ) {
                dp[lane][pos] = dp[lane][pos + 1];
            } else {
                // changing the lane
                int ans = 1e9;
                for( int i = 1; i <= 3; i++ ) {
                    if( i != lane && obstacles[pos] != i ) {
                        ans = min(ans, dp[i][pos + 1] + 1);
                    }
                }

                dp[lane][pos] = ans;
            }
        }
    }

    return min(dp[2][0], min(dp[1][0], dp[3][0]) + 1);
}

int tabulationSO(vector<int>& obstacles) {
    int n = obstacles.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, 0);

    for( int pos = n - 1; pos >= 0; pos-- ) {
        for( int lane = 1; lane <= 3; lane++ ) {
            if( obstacles[pos + 1] != lane ) {
                curr[lane] = next[lane];
            } else {
                // changing the lane
                int ans = 1e9;
                for( int i = 1; i <= 3; i++ ) {
                    if( i != lane && obstacles[pos] != i ) {
                        ans = min(ans, next[i] + 1);
                    }
                }

                curr[lane] = ans;
            }
        }
        next = curr;
    }

    return min(curr[2], min(curr[1], curr[3]) + 1);
}

int minSideJumps(vector<int>& obstacles) {

    // using recursion
    // return recursion(obstacles, 0, 2);

    // using memorization
    // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
    // int ans = memorization(obstacles, 0, 2, dp);

    // return ans;

    // using tabulation
    // return tabulation(obstacles);

    return tabulationSO(obstacles);
}

int main() {

    vector<int> obstacles = { 0,1,2,3,0 };
    // vector<int> obstacles = { 0,3,3,0,3,2,2,0,0,3,0 };

    cout << minSideJumps(obstacles);

    return 0;
}