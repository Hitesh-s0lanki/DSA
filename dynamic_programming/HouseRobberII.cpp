// Time Complexity -> O(2N) -< O(N)
// Space Compexity -> O(1) 

#include <iostream>
#include <vector>

using namespace std;

int solution1(vector<int>& nums) {
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for( int i = 1; i < n - 1; i++ ) {
        int curr = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return max(prev2, prev1);
}

int solution2(vector<int>& nums) {
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[1];

    for( int i = 2; i < n; i++ ) {
        int curr = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return max(prev2, prev1);
}

int rob(vector<int>& nums) {

    if( nums.size() == 1 ) return nums[0];

    return max(solution1(nums), solution2(nums));
}

int main() {

    vector<int> nums = { 2,3,2 };
    // vector<int> nums = { 1,2,3,1 };

    cout << rob(nums);

    return 0;
}