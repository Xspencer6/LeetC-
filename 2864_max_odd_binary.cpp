#include <algorithm>
#include <string>

std::string maximumOddBinaryNumber(std::string s){
    std::sort(s.rbegin(), s.rend());
    // swap the last '1' in sorted string to the laast element s.size() - 1
    for (int i = s.size() - 1; i >= 0; i--){
        if (s[i] == '1') {
            std::swap(s[i], s[s.size() - 1]);  // swap with the last element 0 to form an odd number
        }
    }
    return s;
}