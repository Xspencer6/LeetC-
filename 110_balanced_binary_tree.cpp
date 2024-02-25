#include <iostream>
#include "TreeNode.h"

int maxDepth(TreeNode* root);

bool isBalanced(TreeNode* root);

int main(){

    return 0;
}

int maxDepth(TreeNode* root){
    if (root == nullptr) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(TreeNode* root){
    if (root == nullptr) return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return std::abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
