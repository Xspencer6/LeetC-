#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(std::string s);

int main(){
    std::string test = "tmmzuxt";
    std::cout << lengthOfLongestSubstring(test); // should equal to 5.
    return 0;
}

int lengthOfLongestSubstring(std::string s){
    if (s.size() == 0) return 0;
    int n = s.size();
    int best = 0;
    // use hashmap to keep track of unique substrings
    std::unordered_map <char, int> maps;

    int leftP = 0;  // left pointer 

    // use left and right pointer to iterate through the string
    for (int rightP = 0; rightP < n; rightP++){
        if (maps.count(s[rightP]) == 0 || maps[s[rightP]] < leftP){  // check if char is unique OR if the index of last occurred 
                                                                    // char is less than leftP means it is unique within the current substring
            maps[s[rightP]] = rightP;
            // compare best to current substring
            best = std::max(rightP - leftP + 1, best);
        }
        else{   // means it is a repeated char
            // move left pointer to the next pos of last occurrence of char
            leftP = maps[s[rightP]] + 1;
            // update index of current character
            maps[s[rightP]] = rightP;
        }
    }
    return best;
}