#include <iostream>

using namespace std;

int countSteps(long curr, long next, int n) {

    int steps = 0;

    while( curr <= n ) {
        steps += min(( long )(n + 1), next) - curr;
        curr *= 10;
        next *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {

    int curr = 1;
    k--;

    while( k > 0 ) {
        int steps = countSteps(curr, curr + 1, n);
        if( steps <= k ) {
            curr++;
            k -= steps;
        } else {
            curr *= 10;
            k--;
        }
    }

    return curr;
}

int main() {

    cout << findKthNumber(100, 90);

    return 0;
}