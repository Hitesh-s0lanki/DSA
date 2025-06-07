#include <iostream>
#include <vector>

using namespace std;

int findParent(char ch, vector<int>& parent) {
    if( parent[ch - 'a'] == -1 ) return ch - 'a';

    return parent[ch - 'a'] = findParent('a' + parent[ch - 'a'], parent);
}

void unionSet(vector<int>& parent, string s1, string s2) {

    int n = s1.length();

    for( int i = 0; i < n; i++ ) {
        int u = findParent(s1[i], parent);
        int v = findParent(s2[i], parent);

        if( u > v ) {
            parent[u] = v;
        } else if( u < v ) {
            parent[v] = u;
        }
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.length();

    vector<int> parent(26, -1);
    unionSet(parent, s1, s2);

    string ans;

    for( char ch : baseStr ) {
        int val = findParent(ch, parent);

        if( val != -1 )
            ans.push_back('a' + val);
        else
            ans.push_back(ch);
    }

    return ans;
}

int main() {

    cout << smallestEquivalentString("parker", "morris", "parser");

    return 0;
}