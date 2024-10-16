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
  int pre=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int ls, int le, unordered_map<int, int> &mp)
    {
      if(ls>le) return NULL;

      int node=preorder[pre++];
      TreeNode* root= new TreeNode(node);

      int ind=mp[node];

      root->left=solve(preorder, inorder, ls, ind-1, mp);
      root->right=solve(preorder, inorder, ind+1, le, mp);
      return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
          mp[inorder[i]]=i;
        }

        return solve(preorder, inorder, 0, n-1, mp);
    }
};