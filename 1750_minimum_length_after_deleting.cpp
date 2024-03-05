class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right){
            // check if prefix and suffix is same
            if (s[left] == s[right]){
                // get prefix
                // move left until s[left] is not the same
                while(left < right && s[left] == s[left + 1]){
                    left++;
                }

                // get suffix 
                // move right --
                while (left < right && s[right] == s[right - 1]){
                    right--;
                }
                left++;
                right--;
            }
            else return right - left + 1;
        }
        if (left == right) return 1;
        else return 0;
    }
};