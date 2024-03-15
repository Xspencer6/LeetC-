#include <iostream>
#include <vector>
using namespace std;
/*
this file is used for testing functions or theories in mind.
*/

int main(){
    vector <int> nums = {1, 2, 3, 4};
    vector <int> out;
    int product = 1;
    for (int i = 0; i < nums.size(); ++i){
        product *= nums[i];
        out.push_back(product);
    }

    for (auto i : out){
        cout << i << " ";
    }
    return 0;
}