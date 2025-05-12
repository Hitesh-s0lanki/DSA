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

// pair<int, int> - > height, diameter

pair<int, int> diameterFast(TreeNode* root) {
    if( root == NULL ) {
        return make_pair(0, 0);
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int height = max(left.first, right.first) + 1;
    int dia = max(left.first + right.first, max(left.second, right.second));

    return make_pair(height, dia);
}

int diameter(TreeNode* root) {
    return diameterFast(root).second;
}

int main() {

    vector<int> val = { 1, 2, -1, -1, 3, -1, -1 };
    int index = 0;
    TreeNode* root = buildTree(val, index);

    cout << diameter(root);

    return 0;
}