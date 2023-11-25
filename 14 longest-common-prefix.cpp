class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& words){
    std::string ans = "";

    // sort the vector
    std::sort(words.begin(), words.end());  // sorting allows to see the difference in prefix of first and last item
    int n = words.size();
    std::string first = words[0], second = words[n-1];

    for (int i = 0; i < std::min(first.size(),second.size()); i++){
        if (first[i] != second[i]){ // if the char does not match : return
            return ans;
        }
        // add the common prefix
        ans += first[i];
    }
    return ans;
}

};
