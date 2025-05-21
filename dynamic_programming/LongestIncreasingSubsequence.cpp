#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>>& ans) {
    for( auto i : ans ) {
        for( int j : i )
            cout << j << "\t";
        cout << endl;
    }
}

int recursion(vector<int>& nums, int curr, int prev) {

    if( curr == nums.size() ) return 0;

    // include 
    int take = 0;
    if( prev == -1 || nums[prev] < nums[curr + 1] )
        take = 1 + recursion(nums, curr + 1, curr);

    // exclude
    int exclude = recursion(nums, curr + 1, prev);


    return max(take, exclude);
}

int memorization(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {

    if( curr == nums.size() ) return 0;

    if( dp[curr][prev + 1] != -1 ) return dp[curr][prev + 1];

    // include 
    int include = 0;
    if( prev == -1 || nums[prev] < nums[curr] )
        include = 1 + recursion(nums, curr + 1, curr);

    // exclude
    int exclude = recursion(nums, curr + 1, prev);

    return dp[curr][prev + 1] = max(include, exclude);
}

int tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for( int curr = n - 1; curr >= 0; curr-- ) {
        for( int prev = curr - 1; prev >= -1; prev-- ) {
            int take = 0;
            if( prev == -1 || nums[curr] > nums[prev] ) {
                take = 1 + dp[curr + 1][curr + 1];
            }
            int notTake = dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

int tabulationSO(vector<int>& nums) {
    int n = nums.size();

    vector<int> currArr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for( int curr = n - 1; curr >= 0; curr-- ) {
        for( int prev = curr - 1; prev >= -1; prev-- ) {
            int take = 0;
            if( prev == -1 || nums[curr] > nums[prev] ) {
                take = 1 + next[curr + 1];
            }
            int notTake = next[prev + 1];
            currArr[prev + 1] = max(take, notTake);
        }
        next = currArr;
    }

    return currArr[0];
}

// binary serach + DP
int optimal(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);

    for( int i = 1; i < n; i++ ) {
        if( nums[i] > ans.back() )
            ans.push_back(nums[i]);
        else {
            // find the just bada element 
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }

    return ans.size();
}

int lengthOfLIS(vector<int>& nums) {
    // using recursion
    // return recursion(nums, 0, -1);

    // using memorization
    // int n = nums.size();
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // int ans = memorization(nums, 0, -1, dp);

    // // print(dp);

    // return ans;

    // using tabulation
    // return tabulation(nums);

    // using tabulation + SO
    // return tabulationSO(nums);

    return optimal(nums);
}

int main() {

    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    // vector<int> nums = { 7,7,7,7,7,7,7 };
    // vector<int> nums = { 4,10,4,3,8,9 };

    cout << lengthOfLIS(nums);

    return 0;
}