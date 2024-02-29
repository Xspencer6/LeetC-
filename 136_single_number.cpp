#include <iostream>
#include <vector>
#include <unordered_map>

int singleNumber(std::vector<int> &nums){
    std::unordered_map <int, int> maps;
    for (auto i : nums) maps[i]++;
    for (auto j : maps) if (j.second == 1) return j.first;
    return -1;
}

int main(){
    std::unordered_map <int, int> maps;
    maps[1]++;
    maps[2]++;
    maps[2]++;
    maps[1]++;
    maps[3]++;

    for (auto x : maps) std::cout << x.first << "&&" << x.second;

    return 0;
}