#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( int j : i )
            cout << j << "\t";
        cout << endl;
    }
}

int recursion(vector<int>& satisfaction, int n, int index, int time) {

    if( index >= n ) return 0;

    // include this dish
    int include = (satisfaction[index] * time) + recursion(satisfaction, n, index + 1, time + 1);

    // exclude this dish
    int exclude = recursion(satisfaction, n, index + 1, time);

    return max(include, exclude);
}

int memorization(vector<int>& satisfaction, int n, int index, int time, vector<vector<int>>& dp) {

    if( index >= n ) return 0;

    if( dp[time][index] != -1 ) return dp[time][index];

    // include this dish
    int include = (satisfaction[index] * time) + memorization(satisfaction, n, index + 1, time + 1, dp);

    // exclude this dish
    int exclude = memorization(satisfaction, n, index + 1, time, dp);

    return dp[time][index] = max(include, exclude);
}

int tabulation(vector<int>& satisfaction, int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

    for( int index = n - 1; index >= 0; index-- ) {
        for( int time = n; time >= 0; time-- ) {
            // include this dish
            int include = (satisfaction[index] * time) + dp[time + 1][index + 1];

            // exclude this dish
            int exclude = dp[time][index + 1];

            dp[time][index] = max(include, exclude);
        }
    }

    return dp[1][0];
}

int tabulationSO(vector<int>& satisfaction, int n) {
    vector<int> curr(n + 2, 0);
    vector<int> next(n + 2, 0);

    for( int index = n - 1; index >= 0; index-- ) {
        for( int time = n; time >= 0; time-- ) {
            // include this dish
            int include = (satisfaction[index] * time) + next[time + 1];

            // exclude this dish
            int exclude = curr[time + 1];

            curr[time] = max(include, exclude);
        }

        next = curr;
    }

    return curr[1];
}

int maxSatisfaction(vector<int>& satisfaction) {

    // Get the Size of the Array
    int n = satisfaction.size();

    // Greedy method Get the maximum at the moment
    sort(satisfaction.begin(), satisfaction.end());

    // using recursion
    // return recursion(satisfaction, n, 0, 1);

    // using memorization
    // vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    // int ans = memorization(satisfaction, n, 0, 1, dp);

    // print(dp);

    // return ans;

    // using tabulation
    // return tabulation(satisfaction, n);

    // using space optimize tabulation
    return tabulationSO(satisfaction, n);
}

int main() {

    vector<int> satisfaction = { -1,-8,0,5,-9 };
    // vector<int> satisfaction = { 4, 3, 2 };

    cout << maxSatisfaction(satisfaction);

    return 0;
}