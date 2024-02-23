#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

int main(){
    std::vector <int> num1 = {1,2,0,0};
    std::vector <int> num2 = {3, 4};
    merge(num1, 1, num2, 1);

    for (auto i : num1) std::cout << i << " ";

    return 0;
}


void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
    for (int i = 0, j = m; i < n; i++){
        nums1[j++] = nums2[i];
    }
}