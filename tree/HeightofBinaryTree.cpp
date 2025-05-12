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

int height(TreeNode* root) {
    if( root == NULL ) return -1;

    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    return 0;
}