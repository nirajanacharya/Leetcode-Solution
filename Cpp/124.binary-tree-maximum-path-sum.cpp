/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int answer = INT_MIN;

public:
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int a = max(0, solve(root->left)), b = max(0, solve(root->right));
        int val = root->val;
        answer = max(answer, val + a + b);
        return val + max(a, b);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return answer;
    }
};