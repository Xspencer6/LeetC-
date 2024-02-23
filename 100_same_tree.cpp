#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :  val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* q, TreeNode* p){
    //base case: this will only trigger when one of the nodes reaches NULL
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (q->val == p->val && isSameTree(q->left, p->left) && isSameTree(q->right, p->right));   
}