// Works for both Postive and Negative 
// sequencial adding and mapping them 
// Time Complexity = O(n log n)
// O(n)
// preSumMap.find(x);  // O(log n) for std::map
// unordered_map.find() → O(1) average case (hash table lookup)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>

using namespace std;

int getLongestSubarray(vector<int>& nums, int k) {
    unordered_map<long long, int> preSumMap;

    int n = nums.size();

    int i = 0;
    int sum = 0;
    int longestSubarray = 0;

    while( i < n ) {
        sum += nums[i];

        if( sum == k ) {
            longestSubarray = max(longestSubarray, i + 1);
        }

        long long remaining = sum - k;

        if( preSumMap.find(remaining) != preSumMap.end() ) {
            // means present in the hash table
            int len = i - preSumMap[remaining];
            longestSubarray = max(longestSubarray, len);
        }

        if( preSumMap.find(sum) == preSumMap.end() ) {
            preSumMap[sum] = i;
        }

        i++;
    }

    return longestSubarray;
}

int main() {
    vector<int> a = { 2, 3, 5, 1, 9 };
    long long k = 10;

    cout << "The longest Subarray in only positive is : " << getLongestSubarray(a, k);

    return 0;
}