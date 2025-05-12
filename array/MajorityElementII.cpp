#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    int cnt1 = 0;
    int element1 = -1;

    int cnt2 = 0;
    int element2 = -1;

    for( int i = 0; i < n; i++ ) {
        if( cnt1 == 0 && nums[i] != element2 ) {
            element1 = nums[i];
            cnt1++;
        } else if( cnt2 == 0 && nums[i] != element1 ) {
            element2 = nums[i];
            cnt2++;
        } else if( nums[i] == element1 ) {
            cnt1++;
        } else if( nums[i] == element2 ) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> result;

    // manual check
    cnt1 = 0;
    cnt2 = 0;
    for( int i = 0; i < n; i++ ) {
        if( nums[i] == element1 )
            cnt1++;
        if( nums[i] == element2 )
            cnt2++;
    }

    int mini = ( int )(n / 3) + 1;

    if( cnt1 >= mini )
        result.push_back(element1);
    if( cnt2 >= mini )
        result.push_back(element2);

    return result;

}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    vector<int> nums = { 3,2,3 };

    print(majorityElement(nums));

    return 0;
}