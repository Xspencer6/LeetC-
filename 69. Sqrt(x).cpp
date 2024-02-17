#include <cmath>
#include <iostream>

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

    int squareRoot(double x, double epsilon = 0.00001) {    // this approach uses Newton-Raphson method to find root
    double guess = x; // Initial guess
    int iteration = 0;
    while (true) {
        double difference = (guess * guess - x);
        std::cout << "Difference at iteration " << iteration << ": " << difference << std::endl;
        std::cout << "Guess: " << guess;
        if (std::abs(difference) <= epsilon) // Check for convergence
            break;
        guess = (guess + x / guess) / 2; // Update guess
        iteration++;
    }
    return std::floor(guess);
}

};

int main(){
    Solution s;

    std::cout << s.squareRoot(8.00);

    return 0;
}