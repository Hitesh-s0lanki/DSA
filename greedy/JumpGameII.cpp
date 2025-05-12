#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();

    int cnt = 0;
    int l = 0;
    int r = 0;

    while( r < n - 1 ) {
        int farest = 0;
        for( int i = l; i <= r;i++ ) {
            farest = max(farest, nums[i] + i);
        }

        l = r + 1;
        r = farest;
        cnt++;
    }

    return cnt;
}

int main() {

    vector<int> nums = { 2,3,1,1,4 };
    cout << jump(nums);

    return 0;
}