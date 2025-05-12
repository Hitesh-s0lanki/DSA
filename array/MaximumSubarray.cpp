#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();

    int mini = INT_MIN;

    int sum = 0;

    for( int i = 0; i < n; i++ ) {

        int temp = nums[i] + sum;

        mini = max(mini, temp);

        sum = max(0, temp);
    }

    return mini;
}

int main() {

    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    cout << maxSubArray(nums);

    return 0;
}