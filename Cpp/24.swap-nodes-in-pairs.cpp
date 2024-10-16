/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* it = head;
        ListNode* prev = nullptr;
        ListNode* ans=head->next;
        while(it && it->next){
            ListNode* adjptr=it->next;
            ListNode* nxtptr=adjptr->next;
            adjptr->next=it;
            it->next=nxtptr;
            if(prev){
                prev->next=adjptr;
            }
            prev=it;
            it=nxtptr;
        }
        return ans;
    }
};