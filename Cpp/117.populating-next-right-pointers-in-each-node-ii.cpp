/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void solve(Node* root){
        if(!root){
            return;
        }
        Node* curr=NULL;
        Node* temp=root;
        while(temp && !curr){
            if(temp->next){
                if(temp->next->left){
                    curr=temp->next->left;
                }
                else{
                    curr=temp->next->right;
                }
            }
            temp=temp->next;
        }
        if(root->left && root->right){
            root->left->next=root->right;
            root->right->next=curr;
        }
        else{
            if(root->left){
                root->left->next=curr;
            }
            else if(root->right){
                root->right->next=curr;
            }
        }
        solve(root->right);
        solve(root->left);
    }
public:
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};