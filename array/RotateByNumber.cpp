#include <iostream>
#include <vector>

using namespace std;

void print( vector<int> nums ) {
    for( int num : nums ) {
        cout << num << "\t";
    }
    cout << endl;
}

void reverse( vector<int>& nums, int start, int end )
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

void rotate( vector<int>& nums, int k ) {
    int n = nums.size();
    k = n - (k % n);

    reverse( nums, 0, k - 1 );
    reverse( nums, k, n - 1 );
    reverse( nums, 0, n - 1 );
    print( nums );
}

int main() {

    vector<int> nums = { 1,2,3,4,5,6,7 };

    rotate( nums, 3 );

    return 0;
}