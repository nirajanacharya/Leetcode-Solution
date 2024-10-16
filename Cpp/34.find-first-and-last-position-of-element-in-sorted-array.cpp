class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ve ;
        int s =0;
        int l=nums.size()-1;
        int m = 0;
        int index = 0;
        int sp =-1;
        int lp =-1;
        while(s<=l){
            m=(s+l)/2;
            if(nums[m]==target){
                // cout<<"lp "<<lp<<" m - "<<m<<endl;
                sp=m;
                lp=max(lp,m);
                s=m+1;
            }
            else if(nums[m]>target){
                l=m-1;
            }
            else{
                s=m+1;
            }
        }
        s =0;
        l=nums.size()-1;
        while(s<=l){
            m=(s+l)/2;
            if(nums[m]==target){
                // cout<<"sp "<<sp<<" m - "<<m<<endl;
                sp=min(sp,m);
                l=m-1;
            }
            else if(nums[m]>target){
                l=m-1;
            }
            else{
                s=m+1;
            }
        }
        // cout<<"sp lp:"<<sp<<lp;
        ve.push_back(sp);
        ve.push_back(lp);
        return ve;
    }
};