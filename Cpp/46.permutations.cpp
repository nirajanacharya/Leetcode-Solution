class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> V;
        if(nums.empty())
            return V;
        int a = nums[0];
        nums.erase(nums.begin());
        if(nums.empty())
        {
            V.push_back({a});
            return V;
        }
        vector<vector<int>> V2 = permute(nums);
        for(vector<int> v: V2)
        {
            for(int j=0;j<=v.size();j++)
            {
                vector<int> v2(v);
                v2.insert(v2.begin()+j,a);
                V.push_back(v2);
            }
        }
        return V;
    }
};