class Solution {
    vector<vector<bool>> vis;
    bool backtrack(vector<vector<char>> &board, int i, int j, string &word, int k) {
        if (k == word.size())
            return true;
        vis[i][j]= true;
        if (i and !vis[i-1][j] and board[i-1][j] == word[k] and backtrack(board, i-1, j, word, k+1))
            return true;
        if (i+1 < board.size() and !vis[i+1][j] and board[i+1][j] == word[k] and backtrack(board, i+1, j, word, k+1))
            return true;
        if (j and !vis[i][j-1] and board[i][j-1] == word[k] and backtrack(board, i, j-1, word, k+1))
            return true;
        if (j+1 < board[i].size() and !vis[i][j+1] and board[i][j+1] == word[k] and backtrack(board, i, j+1, word, k+1))
            return true;
        return vis[i][j]= false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vis.resize(board.size(), vector<bool>(board[0].size()));
        int freq[58]= {};
        for (int i= 0; i < board.size(); i++)
            for (int j= 0; j < board[i].size(); j++)
                freq[board[i][j]-'A']++;
        for (const char &c: word)
            if (--freq[c-'A'] < 0)
                return false;
        if (freq[word.front()-'A'] > freq[word.back()-'A'])
            reverse(word.begin(), word.end());
        for (int i= 0; i < board.size(); i++)
            for (int j= 0; j < board[i].size(); j++)
                if (!vis[i][j] and board[i][j] == word[0] and backtrack(board, i, j, word, 1))
                    return true;
        return false;
    }
};
