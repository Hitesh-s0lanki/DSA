#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxIndex = 0;

    int n = nums.size();

    for( int i = 0; i < n; i++ ) {
        int maxJump = nums[i] + i;
        maxIndex = max(maxIndex, maxJump);

        if( maxIndex <= i ) return false;
    }

    return true;
}

int main() {

    vector<int> nums = { 2,3,1,1,4 };

    cout << canJump(nums);

    return 0;
}