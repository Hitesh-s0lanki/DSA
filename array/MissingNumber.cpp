#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int ans = 0;

    for( int i = 1; i <= nums.size(); i++ ) {
        ans ^= nums[i - 1] ^ i;
    }

    return ans;
}

int main() {

    vector<int> nums = { 3,0,1 };

    cout << missingNumber(nums);

    return 0;
}