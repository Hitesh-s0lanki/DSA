#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxDifference(string s) {

    vector<int> freq(26, 0);

    // get the frequency 
    for( auto i : s )
        freq[i - 'a']++;

    int max_even = INT_MAX;
    int max_odd = INT_MIN;

    for( int i = 0; i < 26; i++ ) {

        if( freq[i] == 0 )
            continue;

        if( freq[i] % 2 == 0 )
            max_even = min(max_even, freq[i]);
        else
            max_odd = max(max_odd, freq[i]);
    }

    return max_odd - max_even;
}

int main() {

    cout << maxDifference("aaaaabbc");

    return 0;
}