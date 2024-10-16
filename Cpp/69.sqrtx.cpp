class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x, result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {  // To avoid overflow, use mid <= x / mid instead of mid * mid <= x
                result = mid;  // Update the result as mid might be the answer
                left = mid + 1;  // Try for a bigger value in the right half
            } else {
                right = mid - 1;  // Try for a smaller value in the left half
            }
        }
        
        return result;
    }
};