#include <iostream>

using namespace std;

// Dutch National Flag algorithm

void sortColors(vector<int>& nums) {
    int mid = 0;
    int low = 0;
    int high = nums.size() - 1;

    while( mid <= high ) {
        if( nums[mid] == 0 ) {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        } else if( nums[mid] == 2 ) {
            swap(nums[mid], nums[high]);
            high--;
        } else {
            mid++;
        }
    }
}

int main() {
    return 0;
}