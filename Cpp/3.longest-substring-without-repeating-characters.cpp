class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1); // will store the location of the character
        int n = s.length();
        int l = 0; int  r = 0;
        int maxLen = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1; //repeating allatha postionilott vidunnu
                }
            }
            int len = r-l+1;
            maxLen = max(maxLen , len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};