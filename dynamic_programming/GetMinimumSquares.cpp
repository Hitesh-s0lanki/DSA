#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

void print(vector<int>& ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

int recursion(int n) {

    if( n == 0 ) return 0;

    if( n < 0 ) return INT_MAX;

    int leastNumber = sqrt(n);

    int mini = INT_MAX;

    for( int i = 1; i <= leastNumber; i++ ) {
        int ans = recursion(n - (i * i)) + 1;
        if( ans != INT_MAX ) {
            mini = min(mini, ans);
        }
    }

    return mini;
}

int memorization(int n, vector<int>& dp) {

    if( n == 0 ) return dp[n] = 0;

    if( n < 0 ) return INT_MAX;

    if( dp[n] != -1 ) return dp[n];

    int leastNumber = sqrt(n);

    int mini = INT_MAX;

    for( int i = 1; i <= leastNumber; i++ ) {
        int ans = memorization(n - (i * i), dp) + 1;
        if( ans != INT_MAX ) {
            mini = min(mini, ans);
        }
    }

    return dp[n] = mini;
}

int tabulation(int n) {

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for( int i = 1; i <= n; i++ ) {
        int leastNumber = sqrt(i);
        for( int j = 1; j <= leastNumber; j++ ) {
            if( n - (j * j) >= 0 && dp[i - (j * j)] != INT_MAX ) {
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }
    }

    return dp[n];
}

int MinSquares(int n) {
    // using recursion
    // return recursion(n);

    // using memorization
    // vector<int> dp(n + 1, -1);
    // int ans = memorization(n, dp);
    // print(dp);
    // return ans;


    // using tabulation
    return tabulation(n);
}

int main() {

    cout << (MinSquares(100));

    return 0;
}