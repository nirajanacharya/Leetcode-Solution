class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> copy = matrix;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (copy[i][j] == 0) {
                    for (int p = 0; p < c; p++) {
                        matrix[i][p] = 0;
                    }
                    for (int q = 0; q < r; q++) {
                        matrix[q][j] = 0;
                    }
                }
            }
        }
    }
};
