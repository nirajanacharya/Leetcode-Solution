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
    vector<TreeNode*>f(int l,int r,map<pair<int,int>,vector<TreeNode*>>&mp){
        if(l>r)return mp[{l,r}]={NULL};
        if(l==r){
            TreeNode* x=new TreeNode(l);
            return mp[{l,r}]={x};
        }
        if(mp.find({l,r})!=mp.end())return mp[{l,r}];
         vector<TreeNode*>ans;
        for(int i=l;i<=r;i++){
             auto lbst=f(l,i-1,mp);
             auto rbst=f(i+1,r,mp);
           
             for(auto x:lbst){
                for(auto y:rbst){
                    TreeNode* root =new TreeNode(i);
                    root->left=x;
                    root->right=y;
                    ans.push_back(root);
                }
             }
          
        }
           return mp[{l,r}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>>mp;
        return f(1,n,mp);
    }
};