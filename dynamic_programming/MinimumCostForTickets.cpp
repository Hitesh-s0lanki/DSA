#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void print(vector<int>& ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

int recursion(vector<int>& days, vector<int>& costs, int n, int index) {

    // Base Case
    if( index >= n ) return 0;

    // 1 day pass
    int option1 = costs[0] + recursion(days, costs, n, index + 1);

    // 7 days pass
    int i = index;
    while( i < n && days[i] < days[index] + 7 ) i++;
    int option2 = costs[1] + recursion(days, costs, n, i);

    // 30 days pass
    i = index;
    while( i < n && days[i] < (days[index] + 30) ) i++;
    int option3 = costs[2] + recursion(days, costs, n, i);

    return min(option1, min(option2, option3));
}

int memorization(vector<int>& days, vector<int>& costs, int n, int index, vector<int>& dp) {

    // Base Case
    if( index >= n ) return 0;

    if( dp[index] != -1 ) return dp[index];

    // 1 day pass
    int option1 = costs[0] + memorization(days, costs, n, index + 1, dp);

    // 7 days pass
    int i = index;
    while( i < n && days[i] < days[index] + 7 ) i++;
    int option2 = costs[1] + memorization(days, costs, n, i, dp);

    // 30 days pass
    i = index;
    while( i < n && days[i] < (days[index] + 30) ) i++;
    int option3 = costs[2] + memorization(days, costs, n, i, dp);

    return dp[index] = min(option1, min(option2, option3));
}

int tabulation(vector<int>& days, vector<int>& costs, int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for( int index = n - 1; index >= 0; index-- ) {

        // 1 day pass
        int option1 = costs[0] + dp[index + 1];

        // 7 days pass
        int i = index;
        while( i < n && days[i] < days[index] + 7 ) i++;
        int option2 = costs[1] + dp[i];

        // 30 days pass
        i = index;
        while( i < n && days[i] < (days[index] + 30) ) i++;
        int option3 = costs[2] + dp[i];

        dp[index] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int tabulationSpaceOptimization(vector<int>& days, vector<int>& costs) {

    int ans = 0;

    // queue 
    queue<pair<int, int>> months; // -> first = day , second = cost 
    queue<pair<int, int>> weeks;

    for( int day : days ) {

        while( !months.empty() && months.front().first + 30 <= day )
            months.pop();

        while( !weeks.empty() && weeks.front().first + 7 <= day )
            weeks.pop();

        // add the cost of current day
        months.push(make_pair(day, ans + costs[2]));
        weeks.push(make_pair(day, ans + costs[1]));

        ans = min(ans + costs[0], min(weeks.front().second, months.front().second));
    }

    return ans;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {

    int n = days.size();

    // using recursion
    // return recursion(days, costs, days.size(), 0);

    // using memorization
    // vector<int> dp(n + 1, -1);
    // int ans = memorization(days, costs, n, 0, dp);
    // print(dp);
    // return ans;

    //using tabulation
    // return tabulation(days, costs, n);

    return tabulationSpaceOptimization(days, costs);
}

int main() {

    vector<int> days = { 1,4,6,7,8,20 };
    vector<int> costs = { 2,7,15 };

    // vector<int> days = { 1,2,3,4,5,6,7,8,9,10,30,31 };
    // vector<int> costs = { 2,7,15 };

    cout << mincostTickets(days, costs);

    return 0;
}