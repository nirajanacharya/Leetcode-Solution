/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> mp1;
        Node* dummy = head;
        int count = 1;
        while (dummy) {
            mp1[dummy] = count;
            count++;
            dummy = dummy->next;
        }

        Node* dummyhead = new Node(-1);
        dummy = dummyhead;
        Node* temp = head;
        unordered_map<int, Node*> mp2;
        count = 1;
        while (temp) {
            Node* tmpnode = new Node(temp->val);
            mp2[count] = tmpnode;
            dummy->next = tmpnode;
            dummy = dummy->next;
            temp = temp->next;
            count++;
        }
        Node* newhead = dummyhead->next;
        delete dummyhead;

        dummy = head;
        temp = newhead;
        int rindex;
        while (dummy) {
            Node* randomptr = dummy->random;
            if (randomptr) {
                int rindex = mp1[randomptr];
                // cout<<"ribnde "<<rindex<<endl;
                Node* temprandom = mp2[rindex];
                // cout<<"twmp random value "<<temprandom->val<<endl; 
                temp->random = temprandom;
            }
            temp = temp->next;
            dummy = dummy->next;
        }
        return newhead;
    }
};