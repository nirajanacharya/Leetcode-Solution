class Solution {
public:
    bool helper(int i, int j,int k , string &s1 , string &s2 , string &s3 , vector<vector<int>>&dp){
        if(k >= s3.size())return true;

        if(dp[i][j]!=-1)return dp[i][j];

        bool ans1 = false;
        if(s1[i] == s3[k]){
            ans1 = helper(i+1,j,k+1,s1,s2,s3,dp);
        }
        bool ans2 = false;

        if(s2[j] == s3[k]){
            ans2 = helper(i,j+1,k+1,s1,s2,s3,dp);
        }

        return dp[i][j] = ans1|ans2;
    }
    bool isInterleave(string s1, string s2, string s3) {
       int n = s1.length();
       int m = s2.length();
       int size = s3.size();

       if(n+m != size)return false;
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

       return helper(0,0,0,s1,s2,s3,dp);
    }
};