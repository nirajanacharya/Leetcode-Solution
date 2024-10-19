class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        for (const string& word : words) {
            for (char c : word) {
                indegree[c] = 0; // Initialize indegree
            }
        }
        
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (graph[w1[j]].insert(w2[j]).second) {
                        indegree[w2[j]]++; // Update indegree
                    }
                    break;
                }
            }
        }
        
        queue<char> q;
        for (const auto& [node, degree] : indegree) {
            if (degree == 0) {
                q.push(node);
            }
        }
        
        string order;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            order += curr;
            for (char neighbor : graph[curr]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return order.size() == indegree.size() ? order : ""; // Check if the order is valid
    }
};
