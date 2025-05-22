#include <iostream>
#include <vector>

using namespace std;

bool recursion(vector<int>& nums, int n, int index, int target){

    if(target < 0 || index >= n) return false;

    if(target == 0) return true;

    // include case
    bool take = recursion(nums, n, index + 1, target - nums[index]);

    // exclude
    bool notTake = recursion(nums, n, index + 1, target);

    return (take || notTake);
}

int memorization(vector<int>& nums, int n, int index, int target, vector<vector<int>>& dp){

    if(target < 0 || index >= n) return 0;

    if(target == 0) return 1;

    if(dp[index][target] != -1) return dp[index][target];

    // include case
    int take = memorization(nums, n, index + 1, target - nums[index], dp);

    // exclude
    int notTake = memorization(nums, n, index + 1, target, dp);

    return dp[index][target] = (take || notTake);
}

bool tabulation(vector<int>& nums, int n, int t){

    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for(int index = 1; index <= n; index ++){
        for(int target = 0; target <= t; target++){
            // include case
            int take = 0;
            if((target - nums[index]) >= 0){
                take = dp[index - 1][target - nums[index - 1]];
            }

            // exclude
            int notTake = dp[index - 1][target];

            dp[index][target] = (take || notTake);
        }
    }

    return dp[n][t];
}

bool tabulationOptimized(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // Base case: target 0 can always be made

    for (int num : nums) {
        // Reverse iteration to ensure each number is only used once per state
        for (int t = target; t >= num; t--) {
            dp[t] = dp[t] || dp[t - num];
        }
    }

    return dp[target];
}

bool canPartition(vector<int>& nums) {
    
    int n = nums.size();

    // step 1: check if the sum even or not
    int sum = 0;
    for(int num:nums)
        sum += num;
    
    if(sum % 2 != 0) return false;

    // step 2: check the subarray half the sum

    // using recursion
    // return recursion(nums, n, 0, sum/2);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
    // int ans = memorization(nums, n, 0, sum/2, dp);
    // return ans == 1;

    // using tabulation
    return tabulation(nums, n, sum/2);
}

int main() {

    vector<int> nums = {1,5,11,5};
    // vector<int> nums = {1,2,3,5};

    cout<< canPartition(nums);

    return 0;
} 