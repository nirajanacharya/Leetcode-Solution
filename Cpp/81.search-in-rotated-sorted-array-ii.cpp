class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        int ans=false;

        while(nums[0]==nums[end] && nums.size()!=1&&end!=0){
            end=end-1;
        }
        int h=end;
        while(start<end){
            mid=start+(end-start)/2;
            if(nums[0]<=nums[mid]){
                start=mid+1;
            }
            else{
                end=mid;
            }

        }
        if(target>=nums[end]&&target<=nums[h] && end!=h+1){
            ans=binary(nums,target,end,h);

        }
        else{
            ans=binary(nums,target,0,end-1);
        }
        return ans;    
    }
    bool binary(vector<int>& nums, int target,int start,int end){
        while(start<=end){
            int mid =start+(end-start)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]==target){
                return true;

            }
            else{
                start=mid+1;
            }
        }
        return false;
    }

};