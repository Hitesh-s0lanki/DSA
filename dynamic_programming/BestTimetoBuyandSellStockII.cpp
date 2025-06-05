#include <iostream>
#include <vector>

using namespace std;

int recursion(vector<int>& prices, int index, int buy) {
    if( index == prices.size() ) return 0;

    // take the stock   
    int profit = 0;

    if( buy ) {
        profit = max((-prices[index]) + recursion(prices, index + 1, 0), recursion(prices, index + 1, 1));
    } else {
        profit = max((prices[index] + recursion(prices, index + 1, 1)), (0 + recursion(prices, index + 1, 0)));
    }

    return profit;
}

int memorization(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
    if( index == prices.size() ) return 0;

    if( dp[index][buy] != -1 ) return dp[index][buy];

    // take the stock   
    int profit = 0;

    if( buy ) {
        profit = max((-prices[index]) + recursion(prices, index + 1, 0), recursion(prices, index + 1, 1));
    } else {
        profit = max((prices[index] + recursion(prices, index + 1, 1)), (0 + recursion(prices, index + 1, 0)));
    }

    return dp[index][buy] = profit;
}

int tabulation(vector<int>& prices, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for( int index = n - 1; index >= 0; index-- ) {
        for( int buy = 0; buy <= 1; buy++ ) {
            int profit = 0;

            if( buy ) {
                profit = max((-prices[index]) + dp[index + 1][0], dp[index + 1][1]);
            } else {
                profit = max((prices[index] + dp[index + 1][1]), (0 + dp[index + 1][0]));
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

int tabulationSO(vector<int>& prices, int n) {

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for( int index = n - 1; index >= 0; index-- ) {
        for( int buy = 0; buy <= 1; buy++ ) {
            int profit = 0;

            if( buy ) {
                profit = max((-prices[index]) + next[0], next[1]);
            } else {
                profit = max((prices[index] + next[1]), (0 + next[0]));
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return curr[1];
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();

    // using recursion
    // return recursion(prices, 0, 1);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return memorization(prices, 0, 1, dp);

    // return tabulation(prices, n);
    return tabulationSO(prices, n);
}

int main() {

    vector<int> prices = { 7,1,5,3,6,4 };
    cout << maxProfit(prices);

    return 0;
}