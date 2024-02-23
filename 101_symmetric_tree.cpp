#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool symHelper(TreeNode* left, TreeNode* right){
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr || left->val != right->val) return false;
    return symHelper(left->left, right->right) && symHelper(left->right, right->left);  // if code reaches here, means the value of left and right is EQUAL (proceed to next root)
}

bool isSymmetric(TreeNode* root){
    if (root == nullptr) return true;
    return symHelper(root->left, root->right);  // start with left and right
}