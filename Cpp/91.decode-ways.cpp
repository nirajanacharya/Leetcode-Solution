class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int prev1 = 1, prev2 = 1, curr = 0;

        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                int one = prev1;
                int two = 0;
                if (i < n-1 and s[i] == '1') two = prev2;
                else if (i < n-1 and s[i] == '2' and s[i+1] <= '6') two = prev2;
                curr = one + two;
            }
            else curr = 0;
            
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};