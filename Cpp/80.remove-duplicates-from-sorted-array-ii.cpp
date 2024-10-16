class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int l=0,r=0;
         int n=nums.size();
         if(n==0){
            return 0;
         }
         if(n==1){
            return 1;
         }
        int prv=nums[0];
        int limit_count=0;

        int ans=0;
        while(r<n){
            if(nums[r]==prv){
                limit_count++;
            }
            else if(prv!=nums[r]){
                prv=nums[r];
                limit_count=1;
            }
            if(limit_count>2){
                printf("%d",nums[r]);
                l=r;
                r++;
                while(r<n){
                    if(prv==nums[r] && limit_count>=2){
                        limit_count++;
                        r++;
                    }
                    else{
                        swap(nums[l],nums[r]);
                        if(prv!=nums[l]){
                            printf("%d",prv);
                            if(limit_count>=2){
                            ans+=limit_count-2;
                            }
                            limit_count=1;
                            prv=nums[l];
                        }
                        else limit_count++;
                        l++;
                        r++;
                    }
                }

            }
            r++;
        }
        if(limit_count>2)
        ans+=limit_count-2;
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        n-=ans;
        return n;
        // int ind=0;
        // for(int i=0;i<n-2;i++){
        //     if(nums[i]!=nums[i+2]){
        //         nums[ind++]=nums[i];
        //     }
        // }
        // nums[ind++]=nums[n-2];
        // nums[ind++]=nums[n-1];
        // return ind;



        
    }
};