#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int lengthOfLongestSubstring(std::string s);

int main(){
    std::string test = "tmmzuxt";
    std::cout << lengthOfLongestSubstring(test); // should equal to 5.
    return 0;
}

int lengthOfLongestSubstring(std::string s){        // this approach use hash-mapping to remember index values per occurrence of character
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
/*
This approach uses vector with values initialized as -1 to store index value of characters, if index[s[right]] >= left means it is a repeating char
- same approach above : move left pointer the next position of last occurred character.
- much simpler compared to solution above
- always updates the value of index of character (to determine the position of left pointer if it encounters a repeating character but not in substring yet.)
*/
int longestSubString(string s){               
    if (s.size() == 0) return 0;
    int left = 0;
    vector <int> index(128, -1);    // initialize a list of 128 length with -1 initialzied value.
    int best = 0;

    for (int right = 0; right < s.size(); right++){
        if (index[s[right]] >= left){   // if index of right is greater than left : it is a repeating char
            left = index[s[right]] + 1;  // move to the next char of last occurred
            // compare with current best
            best = max(best, right - left + 1);
        }
        index[s[right]] = right;    // update index of character whether unique or not
        best = max(best, right - left + 1); // check for new best
    }
    return best;
}  