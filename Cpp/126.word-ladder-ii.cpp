class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(endWord) == wordSet.end()) return result;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);
        
        bool found = false;
        
        while (!currentLevel.empty() && !found) {
            for (const string &word : currentLevel) {
                wordSet.erase(word);
            }
            for (const string &word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (wordSet.find(temp) != wordSet.end()) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            swap(currentLevel, nextLevel);
            nextLevel.clear();
        }

        if (found) {
            vector<string> path = {endWord};
            backtrack(result, path, parents, endWord, beginWord);
        }
        
        return result;
    }
    
private:
    void backtrack(vector<vector<string>> &result, vector<string> &path, unordered_map<string, vector<string>> &parents, const string &word, const string &beginWord) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            result.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        
        for (const string &parent : parents[word]) {
            path.push_back(parent);
            backtrack(result, path, parents, parent, beginWord);
            path.pop_back();
        }
    }
};
