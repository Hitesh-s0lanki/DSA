#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    vector<string> ans;

    int n = words.size();

    ans.push_back(words[0]);

    for( int i = 1; i < n; i++ ) {
        if( groups[i] != groups[i - 1] ) {
            ans.push_back(words[i]);
        }
    }

    return ans;
}

int main() {

    vector<string> words = { "e","a","b" };
    vector<int> groups = { 0, 0, 1 };

    print(getLongestSubsequence(words, groups));

    return 0;
}