class Solution {
public:
    bool isPalindrome(int x) {
        size_t reversed = 0, digit = 0, orig = x;
        
        while (x > 0) {
            digit = x % 10;   // gets the last number
            reversed = reversed * 10 + digit;   // move the place value of previous number to right
            x = x/10;   // next iter
        } 
        return reversed == orig;    // will return true if palindrome
    }
};
