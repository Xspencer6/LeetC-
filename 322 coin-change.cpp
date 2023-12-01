class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<long> tab(amount + 1, INT_MAX);
        tab[0] = 0;

        for (int i = 1; i <= amount; i++)
            for (auto coin : coins){
                if (i - coin >= 0) tab[i] = std::min(tab[i], 1 + tab[i - coin]);
            }
        return tab[amount] != INT_MAX ? tab[amount] : -1;
    }
};
