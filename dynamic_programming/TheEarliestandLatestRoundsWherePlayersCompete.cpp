#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

vector<int> recursion(int n, int firstPlayer, int secondPlayer) {
    if( n == 2 || secondPlayer == (n - firstPlayer) ) return { 0, 0 };

    // Get number of player selected
    int selectedPlayer = (n / 2);

    // Number of player are even
    if( n % 2 != 0 )
        selectedPlayer++;

    // change the position for the players
    firstPlayer = firstPlayer > selectedPlayer ? n - firstPlayer : firstPlayer;
    secondPlayer = secondPlayer > selectedPlayer ? n - secondPlayer : secondPlayer;

    cout << firstPlayer << " - vs - " << secondPlayer << " Selected Player -> " << selectedPlayer << endl;

    int resultMin = INT_MAX;
    int resultMax = 0;

    for( int i = 1; i <= min(firstPlayer, secondPlayer); i++ ) {
        for( int j = i + 1; j <= max(firstPlayer, secondPlayer); j++ ) {
            vector<int> temp = recursion(selectedPlayer, i, j);

            resultMin = min(resultMin, temp[0]);
            resultMax = max(resultMax, temp[1]);
        }
    }

    if( resultMin == INT_MAX ) resultMin = 0;

    return { resultMin + 1, resultMax + 1 };
}

vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    return recursion(n, firstPlayer, secondPlayer);
}

int main() {

    int n = 11, firstPlayer = 2, secondPlayer = 4;

    print(earliestAndLatest(n, firstPlayer, secondPlayer));

    return 0;
}