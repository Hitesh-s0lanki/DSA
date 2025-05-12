#include <iostream>

using namespace std;

int countDistinctWays(int nStairs) {

    if( nStairs == 0 || nStairs == 1 ) return nStairs;

    int prev = 1;
    int next = 1;

    for( int i = 2; i <= nStairs; i++ ) {
        int total = prev + next;
        prev = next;
        next = total;
    }

    return next;
}

int main() {

    cout << countDistinctWays(3);

    return 0;
}