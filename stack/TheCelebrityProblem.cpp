#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>>& mat) {

    int n = mat.size();

    stack<int> stack;

    for( int i = 0; i < n; i++ ) {
        stack.push(i);
    }

    while( stack.size() > 1 ) {
        int a = stack.top();
        stack.pop();

        int b = stack.top();
        stack.pop();

        // check if A knows B
        if( mat[a][b] == 1 ) {
            stack.push(b);
        } else {
            stack.push(a);
        }
    }

    int a = stack.top();

    // check the col
    for( int i = 0; i < n; i++ ) {
        if( i != a && mat[a][i] != 0 ) {
            return -1;
        }
    }

    // check the row
    for( int i = 0; i < n; i++ ) {
        if( i != a && mat[i][a] != 1 ) {
            return -1;
        }
    }

    return stack.top();

}

int main() {

    vector<vector<int>> mat = { {1, 1, 0}, {0, 1, 0}, {0, 1, 1} };

    cout << celebrity(mat);

    return 0;
}