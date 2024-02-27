#include "TreeNode.h"
#include <bits/stdc++.h>
#include <queue>

int minDepth(TreeNode* root){
    // Depth-first traversal approach
    if (root == nullptr) return 0;
    if (root->right == nullptr) return 1 + minDepth(root->left);
    if (root->left == nullptr) return 1 + minDepth(root->right);
    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

int minDepthBFS(TreeNode* root){
    // Breadth-first traversal approach
    if (!root) return 0;    // root is empty
    else if (!root->left && !root->right) return 1; // root is a leaf node
    else if (!root->left && root->right) return 1 + minDepth(root->right); // left is null and right is not
    else if (root->left && !root->right) return 1 + minDepth(root->left); // left is not and right is null
    else return 1 + std::min(minDepth(root->left), minDepth(root->right)); // both is not null and get the std::min between left and right
}