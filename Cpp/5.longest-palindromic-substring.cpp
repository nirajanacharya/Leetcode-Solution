class Solution {
public:
    string longestPalindrome(string s) {
        int lens = s.size();
        string ss(lens*2+1, '#');
        for(int i =0; i<lens; i++)
        {
            ss[2*i+1] = s[i];
        }
        int lenss = ss.size();
        int R = 0;
        int C = 0;
        vector<int> dp(lenss);
        for(int i=0; i<lenss; i++)
        {
            int mirror_i = 2*C-i;
            if(i<R)
            {
                dp[i] = min(R-i, dp[mirror_i]);
            }
            while(i+dp[i]+1<lenss && i-dp[i]-1>=0 && ss[i-dp[i]-1]==ss[i+dp[i]+1])
            {
                dp[i]++;
            }
            if(i+dp[i]>R)
            {
                R = i+dp[i];
                C = i;
            }
        }
        int maxIdx = max_element(dp.begin(), dp.end())-dp.begin();
        int maxLen = dp[maxIdx];
        return s.substr((maxIdx-maxLen)/2, maxLen);

    }
};