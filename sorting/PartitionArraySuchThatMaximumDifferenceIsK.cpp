#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partitionArray(vector<int>& nums, int k) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    int cnt = 1;
    int mini = nums[0];

    for( int i = 1; i < n; i++ ) {
        if( nums[i] - mini > k ) {
            mini = nums[i];
            cnt++;
        }
    }

    return cnt;
}

int main() {

    vector<int> nums = { 3,6,1,2,5 };

    cout << partitionArray(nums, 2);

    return 0;
}