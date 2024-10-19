class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2; // Sum of first n natural numbers
        int arraySum = accumulate(nums.begin(), nums.end(), 0);
        return totalSum - arraySum; // The missing number
    }
};
