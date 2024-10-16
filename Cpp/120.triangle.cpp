class Solution {
public:
    int solve(vector<vector<int>>&triangle, int n, int i, int j, vector<vector<int>>&dp){
        if(i==n-1)  return triangle[i][j];
        if(i<0 or j<0 or j>n-1) return 1e9;
        if(dp[i][j]!=-1)    return dp[i][j];
        int down=triangle[i][j]+solve(triangle,n,i+1,j,dp);
        int diag=triangle[i][j]+solve(triangle,n,i+1,j+1,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(triangle,n,0,0,dp);
    }
};