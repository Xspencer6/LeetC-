class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int point = 0;
        for (int i = 0; i < nums.size(); i++) if (nums[i] != 0) nums[point++] = nums[i]; 
        // shift non zero digits to left
        for (;point < nums.size(); point++) nums[point] = 0;
        return;
    }
};
