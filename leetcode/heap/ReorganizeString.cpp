#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

class Compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

string reorganizeString(string s) {

    int n = s.length();
    string ans = "";

    // store the frequency of each character
    vector<int> frequency(26, 0);
    for( int i = 0; i < n; i++ ) {
        frequency[s[i] - 97]++;
    }

    // maxHeap
    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
    for( int i = 0; i < 26; i++ ) {
        if( frequency[i] != 0 ) {
            pq.push(make_pair('a' + i, frequency[i]));
        }
    }

    pair<char, int> prev = make_pair('#', 0);

    while( !pq.empty() ) {
        pair<char, int> top = pq.top();
        pq.pop();

        ans.push_back(top.first);

        if( prev.second > 0 ) {
            pq.push(prev);
        }

        top.second--;
        prev = top;
    }

    if( ans.length() != s.length() ) {
        return "";
    }

    return ans;
}

int main() {

    string s = "aab";

    cout << reorganizeString(s);

    return 0;
}