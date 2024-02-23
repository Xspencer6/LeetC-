#include <iostream>
#include <stack>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}    // default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector <int> answer;
        /*
        - Create an empty stack.
        - Initialize the current node as root.
        - Push the current node to S and set current = current->left until current is NULL
        - If current is NULL and the stack is not empty then:
        - Pop the top item from the stack.
        - Print the popped item and set current = popped_item->right 
        - Go to step 3.
        - If current is NULL and the stack is empty then we are done.
        */
        std::stack <TreeNode*> stack;
        while (root || !stack.empty()){
            while (root){
                stack.push(root);
                root = root->left;
            }
            // when it reaches here, root is now = nullptr
            root = stack.top();     // the last pushed element will be in root (inOrder : left -> root -> right)
            stack.pop();
            answer.push_back(root->val);
            root = root->right;  // after left has been exhausted, time for right
        }
        return answer;
    }
};