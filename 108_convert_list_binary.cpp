#include <iostream>
#include <vector>
#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
TreeNode* binarySearchAllocate(std::vector<int>& nums, int start, int end) {
    /*
    - Uses the binary search approach to allocate root using mid value
    - Use recursion to create new nodes for left and right pointers
    - return root
    */
        if (start <= end){
            int mid = start + (end - start)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = binarySearchAllocate(nums, start, mid - 1);
            root->right = binarySearchAllocate(nums, mid + 1, end);
            return root;
        }
        return nullptr;
    }
    
TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return binarySearchAllocate(nums, 0, nums.size() - 1);
    }