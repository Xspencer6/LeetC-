#include <iostream>
#include <vector>
#include <algorithm>

int climbStairs(int n){     // a bottom-top approach of dynamic programming
    if (n == 1) return 1;
    if (n == 2) return 2;

    // create tabulation and store each answer 
    std::vector <int> tab(n+1);  // initialize values as 0
    tab[1] = 1; // build table
    tab[2] = 2;

    for (int i = 3; i <= n; i++) {   // start from i = 3 since we already provided 1st and 2nd value
        tab[i] = tab[i - 1] + tab[i - 2];
    }

    return tab[n];
}

std::vector <int> mem(46);
int topDownClimbStairs(int n){  // top-down approach
    // base case
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (std::count(mem.begin(), mem.end(), n)){
        return mem[n];
    }
    mem[n] = topDownClimbStairs(n - 1) + topDownClimbStairs(n - 2);
    return mem[n];
}


int main(){
    std::cout << topDownClimbStairs(3);
}