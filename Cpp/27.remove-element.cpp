class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int j = nums.size()-1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]!=val){
                count++;
            }
            if(nums[i]==val){
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin(),nums.end());
        return count;
    }
};