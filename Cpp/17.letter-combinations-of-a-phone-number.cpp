class Solution {
public:
    void backtrack
    (
        string &cfg,
        vector<string> &output,
        const vector<string> &mapping,
        const string &digits,
        const int &N,
        const int &pos
    ) {
        if (pos == N) {
            output.push_back(cfg);
            return;
        }

        for (auto &letter : mapping[digits[pos] - '0']) {
            cfg.push_back(letter);
            backtrack(cfg, output, mapping, digits, N, pos + 1);
            cfg.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        /// Init
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cfg;
        vector<string> output;
        const int N = digits.size();

        /// Process
        if (digits.empty()) {
            return {};
        }

        backtrack(cfg, output, mapping, digits, N, 0);
        return output;
    }
};