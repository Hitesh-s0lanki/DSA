#include <iostream>
#include <vector>

using namespace std;

int recursion(vector<int>& prices, int n, int index, int buy, int limit) {
    if( index == n || limit == 0 ) return 0;

    int ans = 0;

    if( buy ) {
        ans = max(-prices[index] + recursion(prices, n, index + 1, 0, limit), recursion(prices, n, index + 1, 1, limit));
    } else {
        ans = max(prices[index] + recursion(prices, n, index + 1, 1, limit - 1), recursion(prices, n, index + 1, 0, limit));
    }

    return ans;
}

int memorization(vector<int>& prices, int n, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
    if( index == n || limit == 0 ) return 0;

    if( dp[index][buy][limit] != -1 ) return dp[index][buy][limit];

    int ans = 0;

    if( buy ) {
        ans = max(-prices[index] + memorization(prices, n, index + 1, 0, limit, dp), memorization(prices, n, index + 1, 1, limit, dp));
    } else {
        ans = max(prices[index] + memorization(prices, n, index + 1, 1, limit - 1, dp), memorization(prices, n, index + 1, 0, limit, dp));
    }

    return dp[index][buy][limit] = ans;
}

int tabulation(vector<int>& prices, int n) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for( int index = n - 1; index >= 0; index-- ) {
        for( int buy = 0; buy <= 1; buy++ ) {
            for( int limit = 1; limit <= 2; limit++ ) {
                int ans = 0;

                if( buy ) {
                    ans = max(-prices[index] + dp[index + 1][0][limit], dp[index + 1][1][limit]);
                } else {
                    ans = max(prices[index] + dp[index + 1][1][limit - 1], dp[index + 1][0][limit]);
                }

                dp[index][buy][limit] = ans;
            }
        }
    }


    return dp[0][1][2];
}

int tabulationSO(vector<int>& prices, int n) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for( int index = n - 1; index >= 0; index-- ) {
        for( int buy = 0; buy <= 1; buy++ ) {
            for( int limit = 1; limit <= 2; limit++ ) {
                int ans = 0;

                if( buy ) {
                    ans = max(-prices[index] + next[0][limit], next[1][limit]);
                } else {
                    ans = max(prices[index] + next[1][limit - 1], next[0][limit]);
                }

                curr[buy][limit] = ans;
            }
            next = curr;
        }
    }


    return curr[1][2];
}

int maxProfit(vector<int>& prices) {

    int n = prices.size();

    // using recursion 
    // return recursion(prices, n, 0, 1, 2);

    // using memorization 
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return memorization(prices, n, 0, 1, 2, dp);

    // using tabulation
    // return tabulation(prices, n);

    // using tabulation Space Optimization
    return tabulationSO(prices, n);
}

int main() {

    // vector<int> prices = { 3,3,5,0,0,3,1,4 };
    vector<int> prices = { 1,2,3,4,5 };
    cout << maxProfit(prices);

    return 0;
}