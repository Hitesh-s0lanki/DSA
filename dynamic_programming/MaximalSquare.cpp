#include <iostream>
#include <vector>

using namespace std;

int recursion(vector<vector<char>>& matrix, int n, int m, int i, int j, int& maxi) {

    if( i >= n || j >= m ) return 0;

    int right = recursion(matrix, n, m, i, j + 1, maxi);
    int diagonal = recursion(matrix, n, m, i + 1, j + 1, maxi);
    int down = recursion(matrix, n, m, i + 1, j, maxi);

    if( matrix[i][j] == '1' ) {
        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, ans);
        return ans;
    } else {
        return 0;
    }
}

int memorization(vector<vector<char>>& matrix, int n, int m, int i, int j, int& maxi, vector<vector<int>>& dp) {

    if( i >= n || j >= m ) return 0;

    if( dp[i][j] != -1 ) return dp[i][j];

    int right = recursion(matrix, n, m, i, j + 1, maxi);
    int diagonal = recursion(matrix, n, m, i + 1, j + 1, maxi);
    int down = recursion(matrix, n, m, i + 1, j, maxi);

    if( matrix[i][j] == '1' ) {
        dp[i][j] = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    } else {
        return dp[i][j] = 0;
    }
}

int tabulation(vector<vector<char>>& matrix, int row, int col, int& maxi) {

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for( int i = row - 1; i >= 0; i-- ) {
        for( int j = col - 1; j >= 0; j-- ) {
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if( matrix[i][j] == '1' ) {
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return dp[row][col];
}

int tabulationSO(vector<vector<char>>& matrix, int row, int col, int& maxi) {

    vector<int> curr(col + 1, 0);
    vector<int> next(col + 1, 0);

    for( int i = row - 1; i >= 0; i-- ) {
        for( int j = col - 1; j >= 0; j-- ) {
            int right = curr[j + 1];
            int diagonal = next[j + 1];
            int down = next[j];

            if( matrix[i][j] == '1' ) {
                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        next = curr;
    }

    return next[col];
}

int maximalSquare(vector<vector<char>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = 0;

    // using recursion
    // recursion(matrix, n, m, 0, 0, maxi);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // memorization(matrix, n, m, 0, 0, maxi, dp);

    // using tabulation
    // tabulation(matrix, n, m, maxi);

    // using tabulation with space optimization
    tabulationSO(matrix, n, m, maxi);

    return maxi * maxi;
}

int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalSquare(matrix);

    return 0;
}