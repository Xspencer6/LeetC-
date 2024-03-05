#include <vector>
#include <algorithm>


    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        int score = 0, best = 0;
        int left = 0;
        int right = tokens.size() - 1;

        while (left <= right){
            if (power >= tokens[left]){
                // lose tokens[i] power
                power =- tokens[left++];
                // get max
                best = std::max(best, ++score);
            }
            else if (score >= 0){
                // gain tokens[i] power
                power += tokens[right--];   // use right since this will only be possible after first if statement is executed
                // decrement points
                score--;
            }
            else break;
        }
        return best;
    }