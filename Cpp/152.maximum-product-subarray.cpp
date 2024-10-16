class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double res = nums[0], currMin = 1, currMax = 1, tmp;
        for (int i=0; i<nums.size(); i++){
            tmp = nums[i]*currMax;
            currMax = max(max(tmp,nums[i]*currMin), (double)nums[i]);
            currMin = min(min(tmp,nums[i]*currMin), (double)nums[i]);
            res = max(res, currMax);
        }
        return res;
    }
};