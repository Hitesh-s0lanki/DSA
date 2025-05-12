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

// pair<int,int> -> balanced, height

pair<bool, int> isBalancedFast(TreeNode* root) {
    if( root == NULL ) return make_pair(true, 0);

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool balance = abs(left.second - right.second) <= 1 && left.first && right.first;

    return make_pair(balance, max(left.second, right.second) + 1);
}

bool isBalanced(TreeNode* root) {
    return isBalancedFast(root).first;
}

int main() {

    vector<int> val = { 10, 20, 40, -1, -1, 60, -1, -1, 30, -1, -1 };
    int index = 0;

    TreeNode* root = buildTree(val, index);

    cout << isBalanced(root);

    return 0;
}