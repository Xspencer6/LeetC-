#include "TreeNode.h"
#include <algorithm>


int res = 0;

int height(TreeNode* root){
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    res = std::max(res, leftHeight + rightHeight);  // take note of current best diameter
    return std::max(leftHeight, rightHeight) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }