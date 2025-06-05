#include <iostream>
#include <queue>

using namespace std;

int maxVowels(string s, int k) {

    int n = s.length();

    int ans = 0;
    int window = k;
    queue<int> queue;

    for( int i = 0; i < n; i++ ) {
        if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) {

        }
    }
}

int main() {

    string s = "abciiidef";
    int  k = 3;

    cout << maxVowels(s, k);

    return 0;
}