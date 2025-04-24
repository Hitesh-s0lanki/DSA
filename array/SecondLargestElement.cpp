#include <iostream>
#include<vector>

using namespace std;

int secondLargestElement( vector<int>& nums ) {

    int largest = nums[0];
    int slargest = -1;

    for( int i = 1; i < nums.size(); i++ ) {
        if( nums[i] > largest ) {
            slargest = largest;
            largest = nums[i];
        } else if( nums[i] != largest && slargest < nums[i] ) {
            slargest = nums[i];
        }
    }

    return slargest;
}

int main() {

    vector<int> nums = { 8, 8, 7, 6, 5 };

    cout << secondLargestElement( nums ) << endl;

    return 0;
}