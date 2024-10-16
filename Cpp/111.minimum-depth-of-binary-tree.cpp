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
    int speed = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (right == 0 || left == 0)
            return max (left, right) + 1;
        root->left = nullptr;
        root->right = nullptr;
        return min(left, right) + 1;
    }
};