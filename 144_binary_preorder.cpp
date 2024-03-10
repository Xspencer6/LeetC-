#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;

void preorder(TreeNode* root, vector<int> &ans){
    // root -> left -> right
    if (!root) return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }