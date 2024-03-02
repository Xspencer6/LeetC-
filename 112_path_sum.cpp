#include "TreeNode.h"

bool hasPathSum(TreeNode* root, int targetSum){
    if (!root) return false;
    if (root->val == targetSum && !root->left && !root->right) return true; // if the remaining sum is the value of current node and it is a leaf node 
    // call left and right target - value
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main(){
    return 0;
}