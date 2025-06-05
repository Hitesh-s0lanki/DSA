#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int ans = 0;
    int mini = prices[0];

    for( int i = 1; i < n; i++ ) {
        ans = max(ans, prices[i] - mini);
        mini = min(mini, prices[i]);
    }

    return ans;
}

int main() {

    vector<int> prices = { 7,1,5,3,6,4 };
    cout << maxProfit(prices);

    return 0;
}