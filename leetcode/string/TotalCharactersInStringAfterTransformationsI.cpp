#include <iostream>
#include <vector>

using namespace std;

#define M 1000000007

int lengthAfterTransformations(string s, int t) {

    vector<int> charCount(26, 0);

    // store the char count in array
    for( auto ch : s )
        charCount[ch - 'a']++;

    while( t-- ) {

        int zCount = charCount[25];

        for( int i = 25; i > 0; i-- ) {
            charCount[i] = charCount[i - 1] % M;
        }

        charCount[0] = zCount;
        charCount[1] = (charCount[1] + zCount) % M;
    }

    long long ans = 0;
    for( auto i : charCount )
        ans = (ans + i) % M;

    return int(ans);
}

int main() {

    string s = "abcyy";
    int t = 2;

    cout << lengthAfterTransformations(s, t);

    return 0;
}