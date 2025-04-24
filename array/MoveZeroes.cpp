#include <iostream>
#include <vector>

using namespace std;

void print( vector<int> nums ) {
    for( int num : nums ) {
        cout << num << "\t";
    }
    cout << endl;
}

void reverse( vector<int>& nums , int start , int end )
{
    while( start <= end )
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void moveZeroes( vector<int>& nums ) {

    int n = nums.size();

    if( n == 1 ) return;

    // 2 pointer approach 
    int i = 0;
    int j = 1;

    while( j < n ) {
        if( nums[i] == 0 && nums[j] != 0 ) {
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
            j++;
        } else if( nums[i] != 0 && i + 1 != j ) {
            i++;
        } else {
            j++;
        }
    }
}

int main() {

    vector<int> nums = { 2, 1 };

    moveZeroes( nums );

    print( nums );

    return 0;
}