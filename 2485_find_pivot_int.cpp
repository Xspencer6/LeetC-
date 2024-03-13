


int pivotInteger(int n){
    int left = 1;
    int right = n;
    int wholeSum = (n * (n + 1)) / 2;

    while (left <= right){
        int mid = left + (right - left) / 2;
        int halfSum = (mid * (mid + 1)) / 2;
        int lastHalfSum = wholeSum - halfSum + mid;

        if (lastHalfSum == halfSum) return mid;
        else if (halfSum < lastHalfSum) left = mid + 1; // move left to mid + 1 if first half sum is less than second half
        else right = mid - 1;
    }
    return - 1;
}