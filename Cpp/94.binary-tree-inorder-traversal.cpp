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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if (!root) {
            return ans;
        }

        stack<TreeNode*> s;

        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            if (s.empty()) {
                return ans;
            }

            root = s.top();
            s.pop();
            ans.push_back(root->val);

            root = root->right;
        }
    }
};