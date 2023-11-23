class Solution {
public:
    int balancedStringSplit(string s) {
        int Rcount = 0, Lcount = 0, ans = 0;
        for (auto i : s){
            if (i == 'R') Rcount++;
            if (i == 'L') Lcount++;
            if (Rcount == Lcount) ans++;
        }
        return ans;
    }
