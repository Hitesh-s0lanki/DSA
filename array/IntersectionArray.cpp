#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> nums) {
    for( int num : nums ) {
        cout << num << "\t";
    }
    cout << endl;
}

vector<int> findArrayIntersection(vector<int>& arr1, int n, vector<int>& arr2, int m) {

    int i = 0, j = 0;

    vector<int> ans;

    while( i < n && j < m ) {
        if( arr1[i] == arr2[j] ) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if( arr1[i] > arr2[j] ) {
            j++;
        } else {
            i++;
        }
    }

    return ans;

}

int main() {

    vector<int> nums1 = { 3, 4, 6, 7, 9, 9 };
    vector<int> nums2 = { 1, 5, 7, 8, 8 };

    vector<int> ans = findArrayIntersection(nums1, nums1.size(), nums2, nums2.size());

    print(ans);

    return 0;
}