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

void preOrder(TreeNode* root) {
    if( root == NULL ) {
        return;
    }

    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if( root == NULL ) {
        return;
    }

    preOrder(root->left);
    cout << root->data << "\t";
    preOrder(root->right);
}

void postOrder(TreeNode* root) {
    if( root == NULL ) {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << "\t";
}

int main() {

    vector<int> val = {
        97, 46, 12, 6, -1, -1, 9, -1, -1, 3, -1, -1, 37, 7, -1, -1, 31, -1, -1
    };
    int index = 0;

    TreeNode* root = buildTree(val, index);

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);



    return 0;
}