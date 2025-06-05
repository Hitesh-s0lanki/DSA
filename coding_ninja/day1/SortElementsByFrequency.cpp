#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

vector<int> sortByFrequency(const vector<int>& nums) {
    int n = nums.size();

    // stoeing  the frequency of the number
    unordered_map<int, int> freq;
    freq.reserve(n);
    for( int x : nums ) ++freq[x];

    // To maintain the order of the series
    vector<int> distinct;
    distinct.reserve(freq.size()); // size of all unqiue element
    unordered_set<int> visited; // to keep the track of visited element
    visited.reserve(freq.size());

    for( int num : nums )
        if( visited.insert(num).second )
            distinct.push_back(num);


    // create a bucket for the freq
    vector<vector<int>> bucket(n + 1);
    for( int num : distinct )
        bucket[freq[num]].push_back(num);

    // building the result 
    vector<int> result;
    result.reserve(n);
    for( int f = n; f >= 1; f-- ) {
        for( int num : bucket[f] ) {
            for( int i = 0; i < f; i++ )
                result.push_back(num);
        }
    }

    return result;
}

int main() {

    // vector<int> nums = { 2, 5, 2, 8, 5, 6, 8, 8 };
    vector<int> nums = { 35, 47, 45, 6, 31, 27, 50, 17, 24, 18, 5, 27, 47, 16, 49, 39, 16, 10, 18, 23, 49, 26, 4, 32, 47, 50, 13, 16, 33, 30, 29, 15, 42, 5, 19, 40, 33, 4, 2, 23, 32, 32, 35, 34, 2, 24, 8 };
    print(sortByFrequency(nums));
    return 0;
}