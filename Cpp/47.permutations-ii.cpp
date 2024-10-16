class Solution {
public:
vector<vector<int>>answer;
void permute(vector<int>& nums,int i)
{
    if(i==nums.size()-1)
     {
        answer.push_back(nums);
        return;
     }
     int freq[21]={0};
     for(int j=i;j<nums.size();j++)
     {
        if(nums[j]<0){
            if(freq[nums[j]+10]==0){
                swap(nums[i],nums[j]);
                permute(nums,i+1);
                swap(nums[i],nums[j]);
            }
            freq[nums[j]+10]++;
        }
        else{
            if(freq[nums[j]+11]==0){
                swap(nums[i],nums[j]);
                permute(nums,i+1);
                swap(nums[i],nums[j]);
            }
            freq[nums[j]+11]++;
        }

     }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums,0);
        return answer;
    }
};