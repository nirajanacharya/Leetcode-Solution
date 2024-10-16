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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals = {};
        if (root == nullptr)
        {
            return vals;
        }
        stack<TreeNode*> nodes = { };
        nodes.push(root);
        TreeNode* cur;
        while (!nodes.empty())
        {
            cur = nodes.top();
            nodes.pop();
            vals.push_back(cur->val);
            if (cur->right != nullptr)
            {
                nodes.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                nodes.push(cur->left);
            }
        }
        return vals;
    }
};