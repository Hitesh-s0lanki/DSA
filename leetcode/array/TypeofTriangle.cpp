#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string triangleType(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if( nums[0] + nums[1] <= nums[2] )
        return "none";
    if( nums[0] == nums[1] && nums[1] == nums[2] )
        return "equilateral";
    if( nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2] )
        return "isosceles";
    if( nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] &&
        nums[1] + nums[2] > nums[0] )
        return "scalene";

    return "none";
}

int main() {
    vector<int> nums = { 3,3,3 };
    cout << triangleType(nums);

    return 0;
}