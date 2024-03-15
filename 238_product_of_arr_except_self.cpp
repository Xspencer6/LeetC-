#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums){
    std::vector<int> ans;
    if (nums.size() < 1) return ans;

    int product = 1;
    for (int i = 0; i < nums.size(); i++){  // this will initialize the answer values
        product *= nums[i]; // update product value
        ans.push_back(product);
    }

    product = 1;
    for (int i = nums.size() - 1; i > 0; i--){
        ans[i] = product * ans[i-1];
        product *= nums[i];
    }
    // corner case scenario
    ans[0] = product;
    return ans;
}