#include <iostream>
#include <vector>

using namespace std;

int recursion(vector<int>& prices, int n, int fee, int index, int buy) {
    if( index == n ) return 0;

    int profit = 0;

    if( buy ) {
        int buy_stock = -prices[index] + recursion(prices, n, fee, index + 1, 0);
        int skip_stock = 0 + recursion(prices, n, fee, index + 1, 1);

        profit = max(buy_stock, skip_stock);
    } else {
        int sell_stock = prices[index] - fee + recursion(prices, n, fee, index + 1, 1);
        int skip_stock = recursion(prices, n, fee, index + 1, 0);

        profit = max(sell_stock, skip_stock);
    }

    return profit;
}

int memorization(vector<int>& prices, int n, int fee, int index, int buy, vector<vector<int>>& dp) {
    if( index == n ) return 0;

    if( dp[index][buy] != -1 ) return dp[index][buy];

    int profit = 0;

    if( buy ) {
        int buy_stock = -prices[index] + memorization(prices, n, fee, index + 1, 0, dp);
        int skip_stock = 0 + memorization(prices, n, fee, index + 1, 1, dp);

        profit = max(buy_stock, skip_stock);
    } else {
        int sell_stock = prices[index] - fee + memorization(prices, n, fee, index + 1, 1, dp);
        int skip_stock = memorization(prices, n, fee, index + 1, 0, dp);

        profit = max(sell_stock, skip_stock);
    }

    return dp[index][buy] = profit;
}

int tabulation(vector<int>& prices, int n, int fee) {
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    for( int index = n - 1; index >= 0; index-- ) {
        for( int buy = 0; buy <= 1; buy++ ) {
            int profit = 0;

            if( buy ) {
                int buy_stock = -prices[index] + dp[index + 1][0];
                int skip_stock = 0 + dp[index + 1][1];

                profit = max(buy_stock, skip_stock);
            } else {
                int sell_stock = prices[index] - fee + dp[index + 1][1];
                int skip_stock = dp[index + 1][0];

                profit = max(sell_stock, skip_stock);
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

int tabulationSO(vector<int>& prices, int n, int fee) {

    vector<int> curr(2, -1);
    vector<int> next(2, -1);

    for( int index = n - 1; index >= 0; index-- ) {
        for( int buy = 0; buy <= 1; buy++ ) {
            int profit = 0;

            if( buy ) {
                int buy_stock = -prices[index] + next[0];
                int skip_stock = 0 + next[1];

                profit = max(buy_stock, skip_stock);
            } else {
                int sell_stock = prices[index] - fee + next[1];
                int skip_stock = next[0];

                profit = max(sell_stock, skip_stock);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return curr[1];
}

int maxProfit(vector<int>& prices, int fee) {

    int n = prices.size();

    // using recursion
    // return recursion(prices, n, fee, 0, 1);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return memorization(prices, n, fee, 0, 1, dp);

    // using tabulation
    // return tabulation(prices, n, fee);

    // using tabulation with space optimization
    return tabulationSO(prices, n, fee);
}

int main() {
    return 0;
}