class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0;
        int best = nums[0];
        for (int i = 0; i < nums.size(); i++ ) {
            sum = std::max(nums[i], sum + nums[i]);
            best = std::max(sum, best);
        }
        return best;
    }
};
