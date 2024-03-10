#include <unordered_set>
#include <vector>

std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2){
    std::unordered_set<int> maps(nums1.begin(), nums1.end()); // initialize values of nums1
    std::vector <int> ans;
    for (auto num : nums2){
        if (maps.count(num)){
            ans.push_back(num);
            maps.erase(num);    // erase that element to prevent duplication in answer
        }
    }
    return ans;
}