class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int dir[][2], int& m, int& n){
        board[i][j] = 'B';
        for(int k = 0; k < 4; k++){
            int row = i + dir[k][0];
            int col = j + dir[k][1];
            if(row >= 0 && col >= 0 && row < m && col < n && board[row][col] == 'O'){
                dfs(board,row,col,dir,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        //using dfs to solve this one, we can undo the changes if we come across edge 'O'
        
        //get the dimnesions of the board
        int m = board.size();
        int n = board[0].size();
        int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        
        //go through the boundary to check
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(board,0,i,dir,m,n);
            }
            if(board[m-1][i] == 'O'){
                dfs(board,m-1,i,dir,m,n);
            }
        }

        for(int i = 0;i < m; i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0,dir,m,n);
            }
            if(board[i][n-1] == 'O'){
                dfs(board,i,n-1,dir,m,n);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
            }
        }
        } 
};