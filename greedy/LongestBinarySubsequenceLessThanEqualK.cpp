#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int recursion(string s, int k, int index, int len) {
    if( index < 0 || k <= 0 )
        return 0;

    //include this digit 
    int inc = 1 + recursion(s, k - pow(2, len) * (s[index] - '0'), index - 1, len + 1);

    // exclude this digit
    int exc = recursion(s, k, index - 1, len);

    return max(inc, exc);
}

int longestSubsequence(string s, int k) {

    int n = s.length();

    // using recursion
    // return recursion(s, k, n - 1, 0);

    int length = 0;

    long long powerValue = 1;

    for( int i = n - 1; i >= 0; i-- ) {

        if( s[i] == '0' ) {
            length++;
        } else if( powerValue <= k ) {
            k -= powerValue;
            length++;
        }

        if( powerValue <= k ) {
            powerValue <<= 1;
        }
    }

    return length;
}

int main() {

    cout << longestSubsequence("1001010", 5);

    return 0;
}