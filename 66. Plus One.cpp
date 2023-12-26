class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i>= 0; i--){
            if (i == size - 1) digits[i]++; // if last item, increment
            if (digits[i] == 10){ // if the answer is 10, move the 1 to next element
                // check if the next element is valid
                if (i != 0){    // separate 1 and 0
                    digits[i] = 0;
                    digits[i - 1]++;
                }
                else{
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }     
        }
        return digits;
    }
