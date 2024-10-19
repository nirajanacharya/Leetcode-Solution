class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while (root) {
            if (abs(root->val - target) < abs(closest - target)) {
                closest = root->val;
            }
            root = (target < root->val) ? root->left : root->right;
        }
        return closest;
    }
};
