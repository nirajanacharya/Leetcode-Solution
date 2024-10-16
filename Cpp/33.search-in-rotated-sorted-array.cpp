class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size();
        int l = 0;
        while(l<h){
            int m = l + (h-l)/2;
            int num = (nums[m] < nums[0]) == (target < nums[0]) 
                    ? nums[m] : nums[0] > target ? INT_MIN : INT_MAX;
            if(num < target){
                l = m+1;
            }
            else if(num > target) {
                h = m; 
            }
            else 
                return m;
        }
        return -1;
    }
};