#include <iostream>

using namespace std;

int minimumDays(int S, int N, int M) {

    int sunday = S / 7;

    int buyingDays = S - sunday;
    int totalFood = S * M;

    int ans = 0;

    if( totalFood % N == 0 ) {
        ans = totalFood / N;
    } else {
        ans = totalFood / N + 1;
    }

    if( ans <= buyingDays )
        return ans;

    return -1;
}

int main() {

    int s = 10; // number of days a man can survive 
    int n = 9; // food he can buy each day
    int m = 8; // consume per day 

    cout << minimumDays(10, 30, 20);

    return 0;
}