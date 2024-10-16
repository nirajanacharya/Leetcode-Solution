class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n,0), curr(n,0);

        int i = 0, j = 0;
        while(j<n && !obstacleGrid[0][j]) prev[j++] = 1;

        for (int i = 1; i < m; i++){
            for (int j = 0; j < n; j++){ 
                int sum = prev[j];
                if(j>0) sum+=curr[j-1];
                curr[j] = (obstacleGrid[i][j])? 0 : sum;
            }
            prev = curr;
        }

        return prev[n-1];
    }
};