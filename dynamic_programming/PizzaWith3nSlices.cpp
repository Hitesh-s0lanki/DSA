#include <iostream>
#include <vector>

using namespace std;

int recursion(vector<int>& slices, int n, int index, int k) {
    if( k == 0 || index >= n ) return 0;

    int take = slices[index] + recursion(slices, n, index + 2, k - 1);

    int notTake = recursion(slices, n, index + 1, k);

    return max(take, notTake);
}

int memorization(vector<int>& slices, int n, int index, int k, vector<vector<int>>& dp) {
    if( k == 0 || index >= n ) return 0;

    if( dp[index][k] != -1 ) return dp[index][k];

    int take = slices[index] + memorization(slices, n, index + 2, k - 1, dp);

    int notTake = memorization(slices, n, index + 1, k, dp);

    return dp[index][k] = max(take, notTake);
}

int tabulation(vector<int>& slices, int n) {

    vector<vector<int>> dp1(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> dp2(n + 2, vector<int>(n + 2, 0));

    for( int index = n - 2; index >= 0; index-- ) {
        for( int k = 1; k <= n / 3; k++ ) {
            int take = slices[index] + dp1[index + 2][k - 1];

            int notTake = dp1[index + 1][k];

            dp1[index][k] = max(take, notTake);
        }
    }

    for( int index = n - 1; index > 0; index-- ) {
        for( int k = 1; k <= n / 3; k++ ) {
            int take = slices[index] + dp2[index + 2][k - 1];

            int notTake = dp2[index + 1][k];

            dp2[index][k] = max(take, notTake);
        }
    }

    return max(dp1[0][n / 3], dp2[1][n / 3]);
}

int tabulationSO(vector<int>& slices, int n) {

    vector<int> prev1(n + 2, 0);
    vector<int> curr1(n + 2, 0);
    vector<int> next1(n + 2, 0);

    vector<int> prev2(n + 2, 0);
    vector<int> curr2(n + 2, 0);
    vector<int> next2(n + 2, 0);

    for( int index = n - 2; index >= 0; index-- ) {
        for( int k = 1; k <= n / 3; k++ ) {
            int take = slices[index] + next1[k - 1];

            int notTake = curr1[k];

            prev1[k] = max(take, notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    }

    for( int index = n - 1; index > 0; index-- ) {
        for( int k = 1; k <= n / 3; k++ ) {
            int take = slices[index] + next2[k - 1];

            int notTake = curr2[k];

            prev2[k] = max(take, notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    }

    return max(curr1[n / 3], curr2[n / 3]);
}

int maxSizeSlices(vector<int>& slices) {

    int n = slices.size();

    // using recursion
    // return max(recursion(slices, n - 1, 0, n / 3), recursion(slices, n, 1, n / 3));

    // using memorization
    // vector<vector<int>> dp1(n, vector<int>(n, -1));
    // vector<vector<int>> dp2(n, vector<int>(n, -1));
    // int ans = max(memorization(slices, n - 1, 0, n / 3, dp1),
    //     memorization(slices, n, 1, n / 3, dp2));

    // return ans;


    // using tabulation
    return tabulation(slices, n);
}

int main() {

    vector<int> slices = { 1,2,3,4,5,6 };
    cout << maxSizeSlices(slices);

    return 0;
}