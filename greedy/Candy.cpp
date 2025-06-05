#include <iostream>
#include <vector>

using namespace std;

int approach1(vector<int>& ratings) {

    int n = ratings.size();

    vector<int> count(n, 1);

    // left to right;
    for( int i = 1; i < n; i++ ) {
        if( ratings[i] > ratings[i - 1] )
            count[i] = max(count[i], count[i - 1] + 1);
    }

    // right to left;
    for( int i = n - 2; i >= 0; i-- ) {
        if( ratings[i] > ratings[i + 1] )
            count[i] = max(count[i], count[i + 1] + 1);
    }

    int ans = 0;
    for( int i : count )
        ans += i;

    return ans;
}

int approach2(vector<int>& ratings) {
    int n = ratings.size();

    int i = 1;
    int candy = n;

    while( i < n ) {

        if( ratings[i] == ratings[i - 1] ) {
            i++;
            continue;
        }

        int peak = 0;
        while( ratings[i] > ratings[i - 1] ) {
            peak++;
            candy += peak;
            i++;
            if( i == n ) return candy;
        }

        int dip = 0;
        while( i < n && ratings[i] < ratings[i - 1] ) {
            dip++;
            candy += dip;
            i++;
        }

        candy -= min(peak, dip);
    }

    return candy;
}

int candy(vector<int>& ratings) {
    return approach2(ratings);
}

int main() {

    vector<int> ratings = { 1, 2, 2 };
    cout << candy(ratings);

    return 0;
}