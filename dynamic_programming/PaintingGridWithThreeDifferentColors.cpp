#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {

    vector<string> colState;

public:

    void generateColState(string s, char prevChar, int len) {
        if( len == 0 ) {
            colState.push_back(s);
            return;
        }

        for( char ch : {'R', 'G', 'B'} ) {
            if( ch != prevChar ) {
                s.push_back(ch);
                generateColState(s, ch, len - 1);
                s.pop_back();
            }
        }
    }

    int solve(int remCol, int prevIndex, int m, vector<vector<int>>& dp) {
        if( remCol == 0 ) return 1;

        if( dp[remCol][prevIndex] != -1 ) return dp[remCol][prevIndex];

        int ways = 0;
        string prevState = colState[prevIndex];

        for( int i = 0; i < colState.size(); i++ ) {
            if( i == prevIndex ) continue;

            string currState = colState[i];
            bool isValid = true;

            for( int j = 0; j < m; j++ ) {
                if( prevState[j] == currState[j] ) {
                    isValid = false;
                    break;
                }
            }

            if( isValid ) {
                ways = (ways + solve(remCol - 1, i, m, dp)) % MOD;
            }

        }

        return dp[remCol][prevIndex] = ways;
    }

    int colorTheGrid(int m, int n) {

        generateColState("", '#', m);

        int result = 0;

        vector<vector<int>> dp(n + 1, vector<int>(colState.size() + 1, -1));

        for( int i = 0; i < colState.size(); i++ ) {
            result = (result + solve(n - 1, i, m, dp)) % MOD;
        }

        return result;
    }
};


int main() {

    Solution s;

    cout << s.colorTheGrid(3, 3);

    return 0;
}