// Time Complexity -> O(n)
// Space Complexity -> O(minutes)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<int>& viewers, vector<int>& unstable, int minutes) {

    int n = viewers.size();

    int ans = 0;

    int maxi = 0;
    queue<int> queue;

    for( int i = 0; i < n; i++ ) {
        if( queue.size() < minutes && unstable[i] == 1 ) {
            queue.push(viewers[i]);
            maxi += viewers[i];

            ans = max(ans, maxi);
        } else if( !queue.empty() ) {
            maxi -= queue.front();
            queue.pop();
        }
    }

    for( int i = 0; i < n; i++ ) {
        if( unstable[i] == 0 ) {
            ans += viewers[i];
        }
    }

    return ans;
}

int main() {

    vector<int> viewers = { 2, 3, 4, 1, 2, 8, 6, 3 };
    vector<int> unstable = { 1, 0, 1, 0, 1, 0, 1, 0 };
    int minutes = 2;

    cout << solve(viewers, unstable, minutes);

    return 0;
}