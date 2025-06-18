#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( int j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

bool check(int row, int col, int n, int m) {
    return row < n && col < m && row >= 0 && col >= 0;
}

int recursion(vector<vector<int>>& grid, int n, int m, int row, int col) {

    if( row == n - 1 && col == m - 1 )
        return grid[row][col];

    int ans = INT_MAX;

    // Go Right
    if( check(row + 1, col, n, m) )
        ans = min(ans, recursion(grid, n, m, row + 1, col));

    // Go Down
    if( check(row, col + 1, n, m) )
        ans = min(ans, recursion(grid, n, m, row, col + 1));

    return grid[row][col] + ans;
}

int memorization(vector<vector<int>>& grid, int n, int m, int row, int col, vector<vector<int>>& dp) {

    if( row == n - 1 && col == m - 1 )
        return grid[row][col];

    if( dp[row][col] != -1 ) return dp[row][col];

    int ans = INT_MAX;

    // Go Right
    if( check(row + 1, col, n, m) )
        ans = min(ans, recursion(grid, n, m, row + 1, col));

    // Go Down
    if( check(row, col + 1, n, m) )
        ans = min(ans, recursion(grid, n, m, row, col + 1));

    return dp[row][col] = grid[row][col] + ans;
}

int tabulation(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[n - 1][m - 1] = grid[n - 1][m - 1];

    for( int row = n - 1; row >= 0; row-- ) {
        for( int col = m - 1; col >= 0; col-- ) {
            int ans = INT_MAX;

            // Go Right
            if( check(row + 1, col, n, m) )
                ans = min(ans, dp[row + 1][col]);

            // Go Down
            if( check(row, col + 1, n, m) )
                ans = min(ans, dp[row][col + 1]);

            if( ans != INT_MAX )
                dp[row][col] = grid[row][col] + ans;
        }
    }

    return dp[0][0];
}

int tabulationSO(vector<vector<int>>& grid, int n, int m) {

    vector<int> curr(m, 0);
    vector<int> next(m, 0);

    curr[m - 1] = grid[n - 1][m - 1];

    for( int row = n - 1; row >= 0; row-- ) {
        for( int col = m - 1; col >= 0; col-- ) {
            int ans = INT_MAX;

            // Go Right
            if( check(row + 1, col, n, m) )
                ans = min(ans, next[col]);

            // Go Down
            if( check(row, col + 1, n, m) )
                ans = min(ans, curr[col + 1]);

            if( ans != INT_MAX )
                curr[col] = grid[row][col] + ans;
        }
        next = curr;
    }

    return curr[0];
}

int minPathSum(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    // using recursion
    // return recursion(grid, n, m, 0, 0);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int ans = memorization(grid, n, m, 0, 0, dp);
    // return ans;

    // using tabulation
    return tabulation(grid, n, m);
}

int main() {

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };


    cout << minPathSum(grid);

    return 0;
}