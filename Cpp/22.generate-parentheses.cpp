class Solution {
public:
    void dfs(int L, int R, string s, int n, vector<string> &v1){
        if(s.length() == n*2){
            v1.push_back(s);
            return;
        }
        if( L < n ){
            dfs(L + 1, R, s + '(', n, v1);
        }

        if(R < L){
            dfs(L, R+1, s + ')', n, v1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> a;
        dfs(0, 0, "", n, a);
        return a;
    }
};