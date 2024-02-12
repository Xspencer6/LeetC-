class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int left = 1, mid = - 1, right = x;

        while (left <= right){
            mid = left + (right - left) / 2;
            long long square = static_cast<long long> (mid) * mid;  // convert mid to long long data type and store to square
            if (square == x) return mid;
            if (square > x){  // make left = mid + 1
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        // if the code reaches this, this means there is no square 
        // we return the nearest integer for "right" 
        return static_cast<int>(std::round(right));
    }
};
