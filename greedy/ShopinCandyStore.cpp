#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> candyStore(int candies[], int n, int k) {

    sort(candies, candies + n);

    int mini = 0;
    int maxi = 0;

    int ending = n;

    for( int i = 0; i < ending; i++ ) {
        mini += candies[i];
        maxi += candies[n - i - 1];

        ending -= k;
    }


    return { mini, maxi };
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    int n = 4;
    int k = 2;
    int candies[] = { 3, 2, 1, 4 };

    print(candyStore(candies, n, k));


    return 0;
}