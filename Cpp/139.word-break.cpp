// Dynamic Programming - Memoization
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[n] = true;  // Base case: an empty string is always a valid segmentation

        // Iterate from the end of the string to the beginning
        for (int i = n - 1; i >= 0; i--) {
            for (const string& w : wordDict) {
                int len = w.length();
                // Check if the word w can fit starting at index i
                if ((i + len) <= n && s.substr(i, len) == w) {
                    dp[i] = dp[i + len];
                }
                // If we found a valid segmentation starting at index i, no need to check further
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];  // dp[0] tells if the entire string s can be segmented
    }
};


// This Brute force approach was wrong for one of the test cases

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         // Convert vector to unordered_set for efficient lookup
//         std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        
//         std::string word = "";
//         bool flag = false;
        
//         for(int i = 0; i < s.length(); i++) {
//             word = word + s[i];
//             if (wordSet.find(word) != wordSet.end()) {
//                 flag = true;
//                 word = "";
//             } 
//             else 
//             {
//                 flag = false;
//             }
//         }
        
//         return flag;     
//     }
// };