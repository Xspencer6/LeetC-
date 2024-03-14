#include <vector>
#include <unordered_map>

int numSubarraysWithSum(std::vector<int> &nums, int goal){
    int prefixSum = 0;
    int answer = 0;
    std::unordered_map <int, int> maps; // sum and occurrence of that sum key pair

    for (int i = 0; i < nums.size(); i++){
        prefixSum += nums[i];
        if (prefixSum == goal) answer++;

        if (maps.find(prefixSum - goal) != maps.end()){ // 
            answer += maps[prefixSum - goal];
        }

        if (maps.find(prefixSum) != maps.end()) maps[prefixSum]++;    // if that sum exist, increase the count of that sum

        else maps[prefixSum] = 1;   // first time occurrence of that sum
        
    }

    return answer;
}

