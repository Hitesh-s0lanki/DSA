#include <iostream>
#include<vector>

using namespace std;

int removeDuplicates( vector<int>& nums ) {

    // Two Pointer Approach 
    int i = 0;

    for( int j = 1; j < nums.size(); j++ ) {
        if( nums[i] != nums[j] ) {
            i += 1;
            nums[i] = nums[j];
        }
    }

    return i + 1;

}

int main() {

    vector<int> nums = { 0, 0, 3, 3, 5, 6 };

    int n = removeDuplicates( nums );

    for( int i = 0; i < n; i++ ) {
        cout << nums[i] << "\t";
    }

    return 0;
}