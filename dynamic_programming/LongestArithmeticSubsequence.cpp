#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(vector<int>& nums, int index, int diff) {

    if( index == 0 ) return 0;

    int ans = 0;

    for( int j = index - 1; j >= 0; j-- ) {
        if( nums[index] - nums[j] == diff ) {
            ans = max(ans, 1 + solve(nums, j, diff));
        }
    }

    return ans;
}

int bruteForce(vector<int>& nums) {
    int n = nums.size();

    if( n <= 2 ) return n;

    int ans = 0;

    for( int i = 0; i < n - 1; i++ ) {
        for( int j = i + 1; j < n; j++ ) {
            ans = max(ans, 2 + solve(nums, i, nums[j] - nums[i]));
        }
    }

    return ans;
}

// int solveMem(vector<int>& nums, int index, int diff, unordered_map<int, int> dp[]) {

//     if( index == 0 ) return 0;

//     if( dp[index].count(diff) ) return dp[index][diff];

//     int ans = 0;

//     for( int j = index - 1; j >= 0; j-- ) {
//         if( nums[index] - nums[j] == diff ) {
//             ans = max(ans, 1 + solveMem(nums, j, diff, dp));
//         }
//     }

//     return dp[index][diff] = ans;
// }

// int better(vector<int>& nums) {
//     int n = nums.size();

//     if( n <= 2 ) return n;

//     int ans = 0;

//     unordered_map<int, int> dp[n + 1];
//     for( int i = 0; i < n - 1; i++ ) {
//         for( int j = i + 1; j < n; j++ ) {
//             ans = max(ans, 2 + solveMem(nums, i, nums[j] - nums[i], dp));
//         }
//     }

//     return ans;
// }

int tabulation(vector<int>& nums, int n) {
    if( n <= 2 ) return n;

    int ans = 0;

    unordered_map<int, int> dp[n + 1];

    for( int i = 1; i < n; i++ ) {
        for( int j = 0; j < i; j++ ) {

            int diff = nums[i] - nums[j];
            int cnt = 1;

            // check if already exist in dp
            if( dp[j].count(diff) )
                cnt = dp[j][diff];

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

int longestArithSeqLength(vector<int>& nums) {

    // recursion 
    // return bruteForce(nums);

    // using memorization
    // return better(nums);

    int n = nums.size();
    return tabulation(nums, n);
}

int main() {

    vector<int> nums = { 9,4,7,2,10 };

    cout << longestArithSeqLength(nums);

    return 0;
}