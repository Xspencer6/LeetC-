class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(const auto& i : words) {
            string temp = "";
            string word = i;

            // loop to iterate each char in word
            for (auto x : word){
                // if a separator is found and there is a word in temp, push the answer to
                // vector ans
                if (x == separator && temp != "") {ans.push_back(temp); temp= "";}
                // add char to temp if x != separator
                if (x != separator) temp += x;
            }
            // if there is an iterator before the last item, push the remaining chars inside temp
            if (temp != "") ans.push_back(temp);
        }
        return ans;
    }
};
