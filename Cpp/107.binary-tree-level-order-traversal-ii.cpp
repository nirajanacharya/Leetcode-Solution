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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<vector<int>> res;
        if (!root)
            return res;
        bfs.push(root);
        while (!bfs.empty()) {
            int s = bfs.size();
            vector<int> cur_res;
            for (int i = 0; i < s; i++) {
                TreeNode* cur = bfs.front();
                bfs.pop();
                cur_res.push_back(cur->val);
                if (cur->left)
                    bfs.push(cur->left);
                if (cur->right)
                    bfs.push(cur->right);
            }
            res.push_back(cur_res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};