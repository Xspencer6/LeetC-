#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

int maxFrequencyElements(std::vector<int> &nums){
    int result = 0;
    std::unordered_map<int, int> maps;
    for(auto num: nums){
        maps[num]++;
    }
    int max = 0;
    // find the max frequency
    for (auto &i : maps){
        if (max < i.second){
            max = i.second;
        }
    }

    // add all frequency equal to max
    for (auto &i : maps){
        if (i.second == max) result += i.second;
    }
    return result;
}