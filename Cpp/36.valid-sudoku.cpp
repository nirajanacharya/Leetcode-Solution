class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool usedRow[9][9]={}; 
        bool usedCol[9][9]={};
        bool usedGrid[9][9]={};
        for(size_t i{}; i < 9; ++i)
        {
            for(size_t j{}; j < 9; ++j)
            {
                int k = i / 3 * 3 + j / 3;
                char ch  = board[i][j];
                if(int num = ch-'1'; ch != '.')
                {
                    if(usedRow[j][num] || usedCol[i][num] || usedGrid[k][num])
                        return false;

                    usedRow[j][num] = usedCol[i][num] = usedGrid[k][num] = true;
                }
            }
        }
        
        return true;
    }
};