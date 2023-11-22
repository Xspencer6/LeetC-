class Solution {
public:
    int minimumSum(int num) {
        std::string s = to_string(num);
        sort(s.begin(), s.end());
        return (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';    // convert string to int then multiply by 10 for tenths place value
    }
};
