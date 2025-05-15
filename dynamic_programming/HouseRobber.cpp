#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();

    int prev2 = 0;
    int prev1 = 1;

    for( int i = 1; i < n; i++ ) {
        int curr = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return max(prev1, prev2);
}

int main() {

    vector<int> nums = { 1,2,3,1 };

    cout << rob(nums);

    return 0;
}