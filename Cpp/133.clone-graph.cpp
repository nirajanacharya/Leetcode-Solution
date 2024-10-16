/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* root = new Node(node->val,{});
        queue<Node*> q;
        unordered_map<Node*,Node*> mp;
        mp[node] = root;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto i: cur->neighbors){
                if(mp[i]==NULL){
                    Node* temp = new Node(i->val,{});
                    mp[i] = temp;
                    q.push(i);
                }
                mp[cur]->neighbors.push_back(mp[i]);
            }
        }
        return root;
    }
};