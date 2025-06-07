#include <iostream>

using namespace std;

string answerString(string word, int numFriends) {
    int n = word.length();
    string ans;

    for( int i = 0; i < n; i++ )
        ans = max(ans, word.substr(i, min(n - i, n - numFriends + 1)));

    return ans;
}

int main() {
    cout << answerString("dbca", 2);

    return 0;
}