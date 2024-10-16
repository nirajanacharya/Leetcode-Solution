class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int n, int si){

        ans.push_back(ds);
        for(int i=si; i<n; i++){
            if(i>si && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(nums,ans,ds,n,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        solve(nums,ans,ds,n,0);
        return ans;
        
    }
};