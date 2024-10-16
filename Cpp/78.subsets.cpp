class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int i : nums){
            vector<vector<int>> newSubsets = {};

            for (vector<int> curr : res){
                vector<int> temp = curr;
                temp.push_back(i);
                newSubsets.push_back(temp);
            }

            for (auto curr : newSubsets){
                res.push_back(curr);
            }

        }
        return res;
    }
};