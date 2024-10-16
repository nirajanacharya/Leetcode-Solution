class Solution {
public:
    int trap(vector<int>& height) {
        
        // int n=height.size();

        // vector<int>prefixMax(n);
        // vector<int>suffixMax(n);
        // int mx=-1e9;
        // for(int i=0;i<n;++i)
        // {
        //     mx=max(height[i],mx);
        //     prefixMax[i]=mx;
        // }
        // mx=-1e9;
        // for(int i=n-1;i>=0;--i)
        // {
        //     mx=max(mx,height[i]);
        //     suffixMax[i]=mx;
        // }
        // int ans=0;
        // for(int i=0;i<n;++i)
        // {
        //     ans+=(min(prefixMax[i],suffixMax[i])-height[i]);
        // }

        // return ans;

        int n=height.size(),ans=0;
        int leftMax=height[0];
        int rightMax=height[n-1];
        int l=1,r=n-2;

        while(l<=r)
        {
            if(leftMax<rightMax)
            {
                if(height[l]<leftMax)
                {
                    ans+=(leftMax-height[l]);
                }
                else
                {
                    leftMax=height[l];
                }
                l++;
            }
            else{

                if(height[r]<rightMax){
                    ans+=(rightMax-height[r]);
                }
                else
                {
                    rightMax=height[r];
                }

                r--;

            }

        }

        return ans;


    }
};