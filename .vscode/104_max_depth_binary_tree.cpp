#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxDepth_recursion(TreeNode* root){
    if (root == nullptr) return 0;
    else{
        int leftDepth = maxDepth_recursion(root->left);
        int rightDepth = maxDepth_recursion(root->right);

        if (leftDepth > rightDepth) return (leftDepth + 1);
        else return rightDepth + 1;
    }
}

int maxDepth_iter(TreeNode* root){
    int depth = 0;
    std::queue <TreeNode*> queue;
    queue.push(root);
    queue.push(nullptr);
    while (!queue.empty()){
        TreeNode* temp = queue.front(); // get root
        queue.pop();

        if (temp == nullptr) depth++;   // means we finished 1 level

        if (temp != nullptr){
            if (temp->left) queue.push(temp->left);
            if (temp->right) queue.push(temp->right);
        }
        else if (!queue.empty()) queue.push(nullptr);   // pushed null after pushing left and right to indicate we finished 1 level

    }
    return depth;
}