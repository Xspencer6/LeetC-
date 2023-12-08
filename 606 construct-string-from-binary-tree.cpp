class Solution {
public:
    string tree2str(TreeNode* root) {
        std::string ans = std::to_string(root->val);
        if (root->left) ans += "(" + tree2str(root->left) + ")";
        if (root->right){
            if (root->left == nullptr) ans += "()";
            ans += "(" + tree2str(root->right) + ")";
        }
        return ans;
    }
};
