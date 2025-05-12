#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if( root == NULL ) return ans;

    queue<TreeNode* > queue;
    queue.push(root);
    queue.push(NULL);

    vector<int> temp;

    while( !queue.empty() ) {
        TreeNode* front = queue.front();
        queue.pop();

        if( front == NULL ) {
            ans.push_back(temp);
            temp.clear();
            if( !queue.empty() ) {
                queue.push(NULL);
            }
        } else {
            temp.push_back(front->val);

            if( front->left != NULL ) {
                queue.push(front->left);
            }
            if( front->right != NULL ) {
                queue.push(front->right);
            }
        }

    }

    return ans;
}

vector<int> rightSideView(TreeNode* root) {
    vector<vector<int>> level = levelOrder(root);

    vector<int> ans;

    for( int i = 0; i < level.size(); i++ ) {

        int size = level[i].size();

        if( size != 0 ) {
            ans.push_back(level[i][size - 1]);
        }
    }

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( auto j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

void preOrder(TreeNode* root) {
    if( root == NULL ) return;

    cout << root->val << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {

    vector<int> val = { 1, 2, -1, 5, -1, -1, 3, -1, 4, -1, -1 };
    int index = 0;

    TreeNode* root = buildTree(val, index);

    preOrder(root);
    cout << endl;

    print(rightSideView(root));

    return 0;
}