class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        int carry =  0;
        int i = a.size() - 1, j = b.size() - 1; // start with rightmost number
        while (i >= 0 || j >= 0){
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0'; // convert char to integer
            if (j >= 0) sum += b[j--] - '0'; // convert char to integer
            carry = sum / 2; // check for carry
            answer += to_string(sum % 2); // append to the answer the converted int to string
        }
        if (carry) answer += to_string(carry); // check if there's any carry left to be appended
        std::reverse(answer.begin(), answer.end());  // reverse the answer to get the order properly
        return answer;
    }
};
