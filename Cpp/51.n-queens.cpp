class Solution {
public:
    bool isValid(vector<string> &cur, int r, int c, int n) {
        for (int i = r, j = c ; i >= 0 && j >= 0 ; i--, j--) {
            if (cur[i][j] == 'Q') return false; 
        }
        for (int i = r, j = c ; i < n && j >= 0 ; i++, j--) {
            if (cur[i][j] == 'Q') return false; 
        }
        for (int j = 0 ; j < c ; j++) {
            if (cur[r][j] == 'Q') return false; 
        }
        return true; 
    }

    void solve(int col, int n, vector<string> &cur, vector<vector<string>> &res) {
        if (col == n) {
            res.push_back(cur); 
            return; 
        }

        for (int row = 0 ; row < n ; row++) {
            if (isValid(cur, row, col, n)) {
                cur[row][col] = 'Q'; 
                solve(col + 1, n, cur, res); 
                cur[row][col] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res; 
        vector<string> cur(n, string(n, '.')); 
        solve(0, n, cur, res); 
        return res; 
    }
};