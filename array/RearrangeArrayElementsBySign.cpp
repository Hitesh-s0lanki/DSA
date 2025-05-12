#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n);

    int pos = 0;
    int neg = 1;

    for( int i = 0; i < n; i++ ) {
        if( nums[i] < 0 ) {
            ans[neg] = nums[i];
            neg += 2;
        } else {
            ans[pos] = nums[i];
            pos += 2;
        }
    }

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;

}

int main() {

    vector<int> nums = { 3,1,-2,-5,2,-4 };

    print(rearrangeArray(nums));

    return 0;
}