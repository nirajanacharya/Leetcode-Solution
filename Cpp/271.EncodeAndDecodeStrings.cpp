class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        for (const string& str : strs) {
            result += to_string(str.size()) + '#' + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, length));
            i = j + 1 + length; // Move to the next encoded string
        }
        return result;
    }
};
