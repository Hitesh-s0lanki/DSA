#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(vector<int>& val, int& index) {

    if( val[index] == -1 ) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(val[index++]);

    root->left = buildTree(val, index);
    root->right = buildTree(val, index);

    return root;
}

int solve(TreeNode* root) {

    if( root == NULL ) return 0;

    if( root->left == NULL && root->right == NULL ) return 1;

    return solve(root->left) + solve(root->right);
}

int noOfLeafNodes(TreeNode* root) {
    return solve(root);
}

int main() {
    return 0;
}