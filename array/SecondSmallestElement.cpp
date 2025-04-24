#include <iostream>
#include<vector>
#include<climits>

using namespace std;

int secondSmallestElement( vector<int>& nums ) {

    int smallest = nums[0];
    int sSmallest = INT_MAX;

    for( int i = 1; i < nums.size(); i++ ) {
        if( nums[i] < smallest ) {
            sSmallest = smallest;
            smallest = nums[i];
        } else if( nums[i] != smallest && sSmallest > nums[i] ) {
            sSmallest = nums[i];
        }
    }

    return sSmallest;
}

int main() {

    vector<int> nums = { 8, 8, 7, 6, 5, 1, 2, 0 };

    cout << secondSmallestElement( nums ) << endl;

    return 0;
}