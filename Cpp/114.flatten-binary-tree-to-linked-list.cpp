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



 //// WE WILL BE USING REVERSE PREORDER
class Solution {
public:
void flattenutil(TreeNode* root, TreeNode* &prev){
     if(root==NULL) return;
     flattenutil(root->right,prev);
     flattenutil(root->left,prev);
     
     root->right=prev;
     root->left=NULL;
     prev=root;
     
}
    void flatten(TreeNode* root) {
        TreeNode* prev=NULL;
        flattenutil(root,prev);
    }
};