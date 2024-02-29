#include <iostream>
#include <vector>
#include <unordered_map>

int singleNumber(std::vector<int> &nums){
    std::unordered_map <int, int> maps;
    for (int i = 0; i < nums.size() - 1; i++){
        maps[nums[i]] = i;
        // check if last element
        if (nums[i] == nums[nums.size() - 1]){
            // check for duplicates
            for (auto x : maps){
                if (x.second == 1) return x.first;
            }
        }
    }
    return -1;
}

int main(){
    std::unordered_map <int, int> maps;
    maps[1] = 0;
    maps[2] = 1;
    maps[1] = 2;

    for (auto x : maps) std::cout << x.first << "&&" << x.second;

    return 0;
}