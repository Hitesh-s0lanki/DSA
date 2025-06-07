#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tabulationSO(string text1, string text2) {

    int n = text1.length();
    int m = text2.length();

    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    for( int i = n - 1; i >= 0; i-- ) {
        for( int j = m - 1; j >= 0; j-- ) {
            int ans = 0;
            if( text1[i] == text2[j] )
                ans = 1 + next[j + 1];
            else
                ans = max(curr[j + 1], next[j]);

            curr[j] = ans;
        }
        next = curr;
    }

    return curr[0];
}

int longestPalindromeSubseq(string s) {
    string text1 = s;
    reverse(s.begin(), s.end());

    return tabulationSO(text1, s);
}

int main() {

    cout << longestPalindromeSubseq("bbbab");

    return 0;
}