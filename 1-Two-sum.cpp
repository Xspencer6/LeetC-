#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(maps.count(complement))  {   // if the difference of target and maps[i] found inside maps,
                return {maps[complement], i};
            }
            maps[nums[i]] = i;   // store a key-value pair of nums[i]
        }
        return {};
    }
};

template <typename T>
void print_vector(vector<T> vec){
    for (auto i : vec) cout << i << " ";
}

int main(){
    vector<int> nums = {0, 2, 7, 8, 5, 4};

    Solution sample;

    auto ans = sample.twoSum(nums, 9);

    print_vector(ans);
    
    return 0;
}