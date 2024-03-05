#include <vector>
#include <cstdlib>

std::vector<int> sortedSquares(std::vector<int> & nums){
    std::vector<int> answer(nums.size());
    // two pointer 
    int left = 0, right = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--){
        if(std::abs(nums[left]) > std::abs(nums[right])){
            answer[i] = nums[left] * nums[left++];
        }
        else answer[i] = nums[right] * nums[right--];
    }
    return answer;
}
//test