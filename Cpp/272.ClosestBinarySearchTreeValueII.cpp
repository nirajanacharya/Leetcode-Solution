class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        inorderTraversal(root, target, k, result);
        return result;
    }
    
private:
    void inorderTraversal(TreeNode* root, double target, int k, vector<int>& result) {
        if (!root) return;
        inorderTraversal(root->left, target, k, result);
        if (result.size() < k) {
            result.push_back(root->val);
        } else if (abs(root->val - target) < abs(result[0] - target)) {
            result.erase(result.begin());
            result.push_back(root->val);
        } else {
            return; // Early exit if current value is not closer
        }
        inorderTraversal(root->right, target, k, result);
    }
};
