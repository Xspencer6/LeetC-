class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> vals;
        int ans = 0;
        vals['I'] = 1;
        vals['V'] = 5;
        vals['X'] = 10;
        vals['L'] = 50;
        vals['C'] = 100;
        vals['D'] = 500;
        vals['M'] = 1000;

        for (int i = 0; i < s.length(); i++){
            if (vals[s[i]] < vals[s[i+1]]) ans -= vals[s[i]];   // if the value of current key is less than the next key i + 1, then subtract it to the next value
            else ans += vals[s[i]];
        }
        return ans;

    }
};
