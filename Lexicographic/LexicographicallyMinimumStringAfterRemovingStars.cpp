// Time Complexity -> O(n * 26)
// Space Complexity -> O(26 * n)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string clearStars(string s) {

    int n = s.length();
    vector<stack<int>> cnt(26);

    for( int i = 0; i < n; i++ ) {
        if( s[i] != '*' ) {
            cnt[s[i] - 'a'].push(i);
        } else {
            for( int j = 0; j < 26; j++ ) {
                if( !cnt[j].empty() ) {
                    int top = cnt[j].top();
                    s[top] = '*';
                    cnt[j].pop();
                }
            }
        }
    }

    // now remove all the *
    string ans;
    for( int i = 0; i < n; i++ ) {
        if( s[i] != '*' )
            ans.push_back(s[i]);
    }

    return ans;
}

int main() {
    return 0;
}