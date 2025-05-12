#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int element = -1;
    int cnt = 0;

    for( int i = 0; i < nums.size(); i++ ) {
        if( cnt == 0 ) {
            element = nums[i];
        } else if( nums[i] == element ) {
            cnt++;
        } else {
            cnt--;
        }
    }

    return element;
}

int main() {

    vector<int> nums = { 2,2,1,1,1,2,2 };

    cout << majorityElement(nums);

    return 0;
}