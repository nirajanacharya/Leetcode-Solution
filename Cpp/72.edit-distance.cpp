class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        std::vector<int> prev(len2+1, 0);
        std::vector<int> cur(len2+1, 0);
        for(int i = 0; i <= len2; i++){
            prev[i] = i;
        }
        for(int r = 1; r <= len1; r++){
            cur[0] = r;
            for(int c = 1; c <= len2; c++){
                int replace = prev[c-1] + ((word1[r-1] == word2[c-1])? 0:1);
                int dlt = prev[c] + 1;
                int insert = cur[c-1] + 1;
                cur[c] = min(replace, min(dlt, insert));
            }
            swap(prev, cur);
        }

        return prev[len2];
    }
};