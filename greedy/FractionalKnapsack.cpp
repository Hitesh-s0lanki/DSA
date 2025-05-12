#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    int value;
    int weight;

    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

bool compare(pair<double, Item*> a, pair<double, Item*> b) {
    return a.first > b.first;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

    int n = val.size();

    vector<pair<double, Item*>> items;

    for( int i = 0; i < n; i++ ) {
        double perUnit = (1.0 * val[i]) / wt[i];
        items.push_back(make_pair(perUnit, new Item(val[i], wt[i])));
    }

    sort(items.begin(), items.end(), compare);

    for( int i = 0; i < n; i++ ) {
        cout << items[i].first << "\t";
    }

    cout << endl;

    double totalValue = 0;
    for( int i = 0; i < n; i++ ) {
        if( items[i].second->weight > capacity ) {
            // fraction
            totalValue += capacity * items[i].first;
            capacity = 0;
        } else {
            totalValue += items[i].second->value;
            capacity = capacity - items[i].second->weight;
        }
    }

    return totalValue;
}

int main() {

    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 40 };

    cout << fractionalKnapsack(val, wt, 50);

    return 0;
}
