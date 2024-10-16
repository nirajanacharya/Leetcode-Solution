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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<std::vector<int>> ans;
        bool reverse = false;
        while (not q.empty()) {
            std::stack<int> s1;
            int len = static_cast<int>(q.size());
            std::vector<int> curLevel;
            while (len--) {
                auto node = q.front();
                q.pop();
                if (node != nullptr) {
                    if (reverse) {
                       s1.push(node->val);
                    } else {
                        curLevel.push_back(node->val);
                    }
                    if (node->left != nullptr)
                        q.push(node->left);
                    if (node->right != nullptr)
                        q.push(node->right);
                }
            }

            if (reverse) {
                while (not s1.empty()) {
                    curLevel.push_back(s1.top());
                    s1.pop();
                }
            }

            reverse = not reverse;
            if (curLevel.size() > 0)
                ans.push_back(curLevel);
        }

        return ans;
    }
};