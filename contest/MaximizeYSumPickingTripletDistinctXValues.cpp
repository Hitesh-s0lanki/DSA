#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int recursion(vector<int>& x, vector<int>& y, int n, int i, int j, int k) {

    if( i == n || j == n || k == n ) return INT_MIN;

    int ans = INT_MIN;

    if( x[i] != x[j] && x[j] != x[k] && x[k] != x[i] ) {
        ans = max(ans, y[i] + y[j] + y[k]);
    }

    // increase i
    int i_inc = recursion(x, y, n, i + 1, j, k);
    // increase y 
    int j_inc = recursion(x, y, n, i, j + 1, k);
    // increase z 
    int k_inc = recursion(x, y, n, i, j, k + 1);

    ans = max(ans, max(i_inc, max(j_inc, k_inc)));

    return ans;
}

int memorization(vector<int>& x, vector<int>& y, int n, int i, int j, int k, vector<vector<vector<int>>>& dp) {

    if( i == n || j == n || k == n ) return INT_MIN;

    if( dp[i][j][k] != -1 ) return dp[i][j][k];

    int ans = INT_MIN;

    if( x[i] != x[j] && x[j] != x[k] && x[k] != x[i] ) {
        ans = max(ans, y[i] + y[j] + y[k]);
    }

    // increase i
    int i_inc = memorization(x, y, n, i + 1, j, k, dp);
    // increase y 
    int j_inc = memorization(x, y, n, i, j + 1, k, dp);
    // increase z 
    int k_inc = memorization(x, y, n, i, j, k + 1, dp);

    ans = max(ans, max(i_inc, max(j_inc, k_inc)));

    return dp[i][j][k] = ans;
}

int tabulation(vector<int>& x, vector<int>& y, int n) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));

    dp[n][n][n] = INT_MIN;

    for( int i = n - 1; i >= 0; i-- ) {
        for( int j = n - 1; j >= 0; j-- ) {
            for( int k = n - 1; k >= 0; k-- ) {
                int ans = INT_MIN;

                if( x[i] != x[j] && x[j] != x[k] && x[k] != x[i] ) {
                    ans = max(ans, y[i] + y[j] + y[k]);
                }

                // increase i
                int i_inc = dp[i + 1][j][k];
                // increase y 
                int j_inc = dp[i][j + 1][k];
                // increase z 
                int k_inc = dp[i][j][k + 1];

                ans = max(ans, max(i_inc, max(j_inc, k_inc)));

                dp[i][j][k] = ans;
            }
        }
    }

    return dp[0][0][0];

}

// int tabulationSO(vector<int>& x, vector<int>& y, int n) {
//     vector<vector<int>> curr(n + 1, vector<int>(n + 1, INT_MIN));
//     vector<vector<int>> next(n + 1, vector<int>(n + 1, INT_MIN));

//     dp[n][n][n] = INT_MIN;

//     for( int i = n - 1; i >= 0; i-- ) {
//         for( int j = n - 1; j >= 0; j-- ) {
//             for( int k = n - 1; k >= 0; k-- ) {
//                 int ans = INT_MIN;

//                 if( x[i] != x[j] && x[j] != x[k] && x[k] != x[i] ) {
//                     ans = max(ans, y[i] + y[j] + y[k]);
//                 }

//                 // increase i
//                 int i_inc = dp[i + 1][j][k];
//                 // increase y 
//                 int j_inc = dp[i][j + 1][k];
//                 // increase z 
//                 int k_inc = dp[i][j][k + 1];

//                 ans = max(ans, max(i_inc, max(j_inc, k_inc)));

//                 dp[i][j][k] = ans;
//             }
//         }
//     }

//     return dp[0][0][0];

// }


int optimal(vector<int>& x, vector<int>& y) {
    int n = x.size();

    unordered_map<int, int> best;
    best.reserve(n);

    for( int i = 0; i < n; i++ ) {
        auto it = best.find(x[i]);
        if( it == best.end() || y[i] > it->second ) {
            best[x[i]] = y[i];
        }
    }

    if( best.size() < 3 ) return -1;

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for( auto i : best ) {
        int val = i.second;
        if( val > first ) {
            third = second;
            second = first;
            first = val;
        } else if( val > second ) {
            third = second;
            second = val;
        } else if( val > third ) {
            third = val;
        }
    }

    return first + second + third;
}

int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {

    // int n = x.size();

    // using recursion
    // int ans = recursion(x, y, x.size(), 0, 0, 0);
    // return ans != INT_MIN ? ans : -1;

    // using memorization
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    // int ans = memorization(x, y, x.size(), 0, 0, 0, dp);
    // return ans != INT_MIN ? ans : -1;

    // using tabulation
    // int ans = tabulation(x, y, n);
    // return ans != INT_MIN ? ans : -1;

    return optimal(x, y);
}

int main() {

    vector<int> x = { 1,2,1,3,2 }, y = { 5,3,4,6,2 };
    // vector<int> x = { 1,2,1,2 }, y = { 4,5,6,7 };

    cout << maxSumDistinctTriplet(x, y);

    return 0;
}