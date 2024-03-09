#include <vector>
#include <map>

int getCommon(std::vector<int> &nums1, std::vector<int> &nums2){
    int res = -1;
    std::map<int, int> maps;

    for (auto num : nums1) maps[num]++;

    // iterate through the nums 2 and compare it to hash map
    for (auto num : nums2){
        if (maps.count(num)){
            return num;
        }
    }
    return res;
}