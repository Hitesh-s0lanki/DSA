#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

void traversal(Node* root, vector<string>& ans, string s) {
    if( root->left == NULL && root->right == NULL ) {
        ans.push_back(s);
        return;
    }

    traversal(root->left, ans, s + "0");
    traversal(root->right, ans, s + "1");
}

vector<string> huffmanCodes(string S, vector<int> f, int N) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for( auto i : f )
        pq.push(new Node(i));

    while( pq.size() > 1 ) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* temp = new Node(left->data + right->data);
        temp->left = left;
        temp->right = right;

        pq.push(temp);
    }

    Node* root = pq.top();
    pq.pop();

    vector<string> ans;
    traversal(root, ans, "");

    return ans;
}

void print(vector<string> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {



    return 0;
}