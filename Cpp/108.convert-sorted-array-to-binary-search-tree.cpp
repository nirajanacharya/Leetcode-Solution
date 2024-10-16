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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int st, int end) {

        if(st > end){
            return nullptr;
        }
       int mid = (st+end)/2; 
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(nums,st,mid -1);
        root->right=sortedArrayToBST(nums,mid + 1,end);
        return root;
    }
};

void preorder(TreeNode* root){
    if(root == nullptr){
        return ;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}