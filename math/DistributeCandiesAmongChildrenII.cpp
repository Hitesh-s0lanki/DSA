#include <iostream>
#include <vector>

using namespace std;

// Time Complexity -> O(target^3)
long long recursion(int n, int target, int limit) {
    if( target == 0 && n == 0 ) return 1;

    if( target < 0 || n <= 0 ) return 0;

    long long ans = 0;

    for( int i = 0; i <= limit; i++ )
        ans += recursion(n - 1, target - i, limit);

    return ans;
}

long long approach2(int target, int limit) {
    long long ans = 0;

    for( int ch1 = 0; ch1 <= min(target, limit); ch1++ ) {
        for( int ch2 = 0; ch2 <= min(limit, target - ch1); ch2++ ) {
            long long ch3 = target - ch1 - ch2;
            if( ch3 <= limit && ch3 >= 0 ) ans += 1;
        }
    }

    return ans;
}

long long approach3(int target, int limit) {
    long long ans = 0;

    int mini = max(0, target - (2 * limit));
    int maxi = min(target, limit);

    for( int ch1 = mini; ch1 <= maxi; ch1++ ) {

        // on 2 children case
        int left_candies = target - ch1;

        int ch2_mini = max(0, left_candies - limit);
        int ch2_maxi = min(left_candies, limit);

        ans += (ch2_maxi - ch2_mini + 1);
    }

    return ans;
}

long long distributeCandies(int target, int limit) {
    // using recurison
    // return recursion(3, target, limit);

    // return approach2(target, limit);
    return approach3(target, limit);
}

int main() {

    // cout << distributeCandies(5, 2);
    cout << distributeCandies(3, 3);

    return 0;
}