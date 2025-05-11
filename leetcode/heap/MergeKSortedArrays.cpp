#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};


class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>& nums, int n) {

    // required data structure 
    vector<int> ans;
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // push the first node of array in quuee
    for( int i = 0; i < n; i++ ) {
        pq.push(new Node(nums[i][0], i, 0));
    }

    //now show time
    while( !pq.empty() ) {
        Node* top = pq.top();
        pq.pop();

        ans.push_back(top->data);

        if( nums[top->row].size() - 1 > top->col ) {
            pq.push(new Node(nums[top->row][top->col + 1], top->row, top->col + 1));
        }
    }

    return ans;
}

void print(vector<int> ans) {
    for( int i : ans ) {
        cout << i << "\t";
    }
    cout << endl;
}

int main() {

    vector<vector<int>> nums = {
       {3, 5, 9},
       {1, 2, 3, 8}
    };

    print(mergeKSortedArrays(nums, nums.size()));

    return 0;
}