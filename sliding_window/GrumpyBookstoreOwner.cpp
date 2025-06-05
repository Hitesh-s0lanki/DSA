#include <iostream>
#include <vector>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

    int n = customers.size();

    int alwaysSat = 0;
    int bestWindow = 0;
    int window = 0;

    for( int i = 0; i < n; i++ ) {

        if( grumpy[i] == 0 ) {
            alwaysSat += customers[i];
        }

        if( grumpy[i] == 1 ) {
            window += customers[i];
        }

        if( i >= minutes && grumpy[i - minutes] == 1 ) {
            window -= customers[i - minutes];
        }

        bestWindow = max(bestWindow, window);
    }

    return alwaysSat + bestWindow;
}

int main() {

    vector<int> customers = { 1,0,1,2,1,1,7,5 };
    vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
    int minutes = 3;

    cout << maxSatisfied(customers, grumpy, minutes);

    return 0;
}