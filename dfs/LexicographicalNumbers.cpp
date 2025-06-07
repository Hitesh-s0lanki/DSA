#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

void dfs(int i, int n, vector<int>& ans) {
    if( i > n ) return;

    ans.push_back(i);

    i *= 10;

    for( int j = 0; j < 10; j++ )
        dfs(i + j, n, ans);
}

vector<int> lexicalOrder(int n) {

    vector<int> ans;

    for( int i = 1; i <= 9; i++ )
        dfs(i, n, ans);

    return ans;
}

int main() {

    print(lexicalOrder(13));

    return 0;
}