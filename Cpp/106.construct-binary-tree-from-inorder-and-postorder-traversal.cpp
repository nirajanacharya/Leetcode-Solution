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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, mp);
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inst, int inend, int pst, int pend, unordered_map<int, int>& mp) {
        if (inst > inend || pst > pend) return NULL;

        int rootVal = postorder[pend];
        TreeNode* root = new TreeNode(rootVal);
        int rootidx = mp[rootVal];
        int lefttree = rootidx - inst;
        root->left = solve(inorder, postorder, inst, rootidx - 1, pst, pst + lefttree - 1, mp);
        root->right = solve(inorder, postorder, rootidx + 1, inend, pst + lefttree, pend - 1, mp);
        return root;
    }
};
