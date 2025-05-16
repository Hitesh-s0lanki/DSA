#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> ans) {
    for( string i : ans )
        cout << i << "\t";
    cout << endl;
}

vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

    int n = words.size();

    vector<string> ans;
    vector<string> temp;

    temp.push_back(words[0]);

    int maxi = 1;
    int lastIndex = 0;

    for( int i = 1; i < n; i++ ) {
        if( groups[i] != groups[i - 1] && (i - lastIndex) == 1 ) {
            temp.push_back(words[i]);
            maxi++;
            lastIndex = i;
        } else {
            if( ans.size() <= maxi ) {
                ans = temp;
            }
            temp.clear();
            maxi = 0;
            lastIndex = 0;
        }
    }

    return ans;
}

int main() {

    vector<string> words = { "bab","dab","cab" };
    vector<int> groups = { 1,2,2 };

    print(getWordsInLongestSubsequence(words, groups));

    return 0;
}