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
    void helper(vector<vector<int>>& res, TreeNode* cur, vector<int>& ans, int targetSum) {
        if (cur == nullptr) {
            return;
        }
        ans.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr && targetSum == cur->val)
            res.push_back(ans);
        helper(res, cur->left, ans, targetSum-cur->val);
        helper(res, cur->right, ans, targetSum-cur->val);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(res, root, ans, targetSum);
        return res;
    }
};