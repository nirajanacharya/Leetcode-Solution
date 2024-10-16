class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    // bool isPal(string& s, int i, int j){
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // long long f(string &s, int i, int j,vector<vector<int>>& dp){
    //     if(i>=j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(isPal(s,i,j)) return dp[i][j] = 0;
    //     long long mini = INT_MAX;
    //     for(int k = i; k<=j; k++){
    //         if(isPal(s,i,k)) mini = min(mini,1+f(s,k+1,j,dp));
    //     }
    //     return dp[i][j] = mini;
    // }
    int minCut(string s) {
        int n = s.length();
        int pal[n+1];
        for (int i=0; i<=n; i++) pal[i]=i-1;
        vector<int> d1(n),d2(n);
        
        for (int i = 0, l1 = 0,l2=0, r1 = -1, r2= -1; i < n; i++) {
            int k = (i > r1) ? 1 : min(d1[l1 + r1 - i], r1 - i + 1);
            pal[i+1] = min(pal[i+1],pal[i]+1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                pal[i+k+1] = min(pal[i+k+1],pal[i-k]+1);
                k++;
            }
            d1[i] = k--;
            if (i + k > r1) {
                l1 = i - k;
                r1 = i + k;
            }
            if (i-1>=0  && s[i]==s[i-1])
                pal[i+1] = min(pal[i+1],pal[i-1]+1);
            k = (i > r2) ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                pal[i+k+1] = min(pal[i+k+1],pal[i-k-1]+1); 
                k++;
            }
            d2[i] = k--;
            if (i + k > r2) {
                l2 = i - k - 1;
                r2 = i + k ; 
            }   
            if(i==n-1 && r2==i){
			int j = i-1;
				while( j >= l2)
					pal[r2+1] = min (pal[r2+1], 1 + pal[j--]);
			}            
        }            
        return pal[n];
    }
};