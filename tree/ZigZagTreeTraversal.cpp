// time - O(N) 
// space - O(N)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(vector<int>& val, int& index) {

    if( val[index] == -1 ) {
        index++;
        return NULL;
    }

    Node* root = new Node(val[index++]);

    root->left = buildTree(val, index);
    root->right = buildTree(val, index);

    return root;
}

int countNode(Node* root) {
    if( root == NULL ) return 0;

    return 1 + countNode(root->left) + countNode(root->right);
}

vector<int> zigZagTraversal(Node* root) {

    int leaveCount = countNode(root);

    vector<int> ans(leaveCount);

    queue<Node*> queue;
    queue.push(root);

    bool zig = true;
    int lastIndex = 0;

    while( !queue.empty() ) {
        int size = queue.size();
        int index = zig ? lastIndex : lastIndex + size - 1;
        lastIndex += size;

        while( size != 0 ) {
            Node* front = queue.front();
            queue.pop();

            ans[index] = front->val;

            if( zig ) {
                index++;
            } else {
                index--;
            }

            if( front->left ) queue.push(front->left);
            if( front->right ) queue.push(front->right);

            size--;
        }

        zig = !zig;
    }


    return ans;

}

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    // 1, 3, 2, 4, 5, 6, 7
    vector<int> val = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };
    int index = 0;

    Node* root = buildTree(val, index);

    print(zigZagTraversal(root));

    return 0;
}