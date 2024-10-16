/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        std::stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int max_depth = 0;
        
        while (!stack.empty()) {
            pair<TreeNode*, int> pair = stack.top();
            stack.pop();
            
            if (pair.first) {
                max_depth = max(max_depth, pair.second);
                stack.push({pair.first->left, pair.second + 1});
                stack.push({pair.first->right, pair.second + 1});
            }
        }
        
        return max_depth;
    }
};

// O(n) time and O(n) space