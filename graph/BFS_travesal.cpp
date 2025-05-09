#include <iostream>
#include<vector>
#include<queue>

using namespace std;


vector<int> bfsTraversal(int n, vector<vector<int>>& adj) {

    vector<int> visited(n);
    vector<int> ans;

    queue<int> q;
    visited[0] = 1;
    q.push(0);

    while( !q.empty() ) {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for( int i : adj[frontNode] ) {
            if( visited[i] == 0 ) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return ans;
}

void print(vector<int> ans) {
    for( int i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}


int main() {

    vector<vector<int>> adjs = { {1,2,3},{4}, {5}, {},{},{} };

    print(bfsTraversal(6, adjs));

    return 0;
}