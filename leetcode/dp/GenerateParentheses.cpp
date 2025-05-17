// Time Complexity -> O(nCn)
// Space Complexity -> O(n)

#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

void recursion(int openP, int closeP, int n, string s, vector<string>& ans) {
    if( openP == closeP && openP + closeP == n * 2 ) {
        ans.push_back(s);
        return;
    }

    if( openP < n ) {
        recursion(openP + 1, closeP, n, s + "(", ans);
    }

    if( closeP < openP ) {
        recursion(openP, closeP + 1, n, s + ")", ans);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    recursion(0, 0, n, "", ans);
    return ans;
}

int main() {

    print(generateParenthesis(3));

    return 0;
}