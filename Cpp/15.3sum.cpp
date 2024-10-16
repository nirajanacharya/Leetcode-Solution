class Solution {
public:
    //int speed= []{std::ios::sync_with_stdio(0);std::cin.tie(0);return 0;}();
    vector<vector<int>> findTwoSum(vector<int>&nums,int l,int r,int sum) {
        int temp = 0;
        vector<vector<int>> res;
        while(l<r) {
            int temp = nums[l] + nums[r];
            if(temp == sum){
                res.push_back({sum*-1,nums[l++],nums[r--]});
            } 
            else if(temp > sum)
                {
                    r--;
                }
            else {
                l++;
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {if (all_of(nums.begin(),nums.end(),[&](const int i) {return i == 0;})) return {{0,0,0}};
        int min = *min_element(nums.begin(), nums.end()), max = *max_element(nums.begin(), nums.end()), target;
        if (min >= 0 || max <= 0) return {};
        int range = max - min + 1, exist = 0;
        vector<int> count(range, 0);
        for(int& i : nums) ++count[i - min];
        for(int i = 0; i < range; i++){
            if(count[i] !=0) nums[exist++] = i + min;
        }
        vector<vector<int>> triples;
        auto l = nums.begin(), r = next(l, exist - 1);
        while(*l <=0){
            while (*r >= 0){
                target = -(*l + *r);
                if (target < *l) {
                    --r;
                    continue;
                }
                if (target > *r) break;
                if (((*l == target || *r == target) && count[target - min] == 1) || 
                ((*l == target && *r == target ) && count[target - min] == 2)){
                    --r;
                    continue;
                }
                if (count[target - min] !=0 ) triples.push_back({*l, target, *r});
                r--;
            }
            ++l;
            r = next(nums.begin(), exist - 1);
        }
        return triples;
        sort(nums.begin(),nums.end());
        set<vector<int>> result;vector<vector<int>> x;

        for(int i=0;i<nums.size()-2;i++) {
            vector<vector<int>> temp = findTwoSum(nums,i+1,nums.size()-1,nums[i]*-1);
            for(int j=0;j<temp.size();j++) {
                result.insert(temp[j]);
            }
        }for(auto it : result){
            x.push_back(it);
        }
        return x;
        
    }
};