#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

TreeNode* buildTree(vector<int> val, int& index) {

    if( val[index] == -1 ) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(val[index++]);

    root->left = buildTree(val, index);
    root->right = buildTree(val, index);

    return root;
}

int countNode(TreeNode* root) {
    if( root == NULL ) return 0;

    return 1 + countNode(root->left) + countNode(root->right);
}

bool isCBT(TreeNode* root, int total, int index) {
    if( root == NULL ) return true;

    if( index >= total ) return false;

    return isCBT(root->left, total, (2 * index) + 1) && isCBT(root->right, total, (2 * index) + 2);
}

bool isMaxOrder(TreeNode* root) {
    if( root == NULL ) return true;

    if( root->left && root->left->data > root->data ) return false;
    if( root->right && root->right->data > root->data ) return false;

    return isMaxOrder(root->left) && isMaxOrder(root->right);
}

bool isHeap(TreeNode* root) {
    int total = countNode(root);

    cout << total << endl;
    int index = 0;

    if( isCBT(root, total, index) && isMaxOrder(root) ) {
        return true;
    }

    return false;
}


int main() {

    // vector<int> val = { 97, 46, 12, 6, -1, -1, 9, -1, -1, 3, -1, -1, 37, 7, -1, -1, 31, -1, -1 };
    // vector<int> val = { 97, 46, 12, 6, -1, -1, -1, 3, 2, -1, -1, 4, -1, -1, 37, 7, -1, -1, 31, -1, -1 };
    vector<int> val = { 6, 4, -1, 2, -1, -1, 3, -1, -1 };
    int index = 0;

    TreeNode* root = buildTree(val, index);

    cout << "I the tree heap or not  : " << isHeap(root);

    return 0;
}